package org.rohling.service.implementation;

import lombok.RequiredArgsConstructor;
import org.rohling.domain.entity.Client;
import org.rohling.domain.entity.ItemOrder;
import org.rohling.domain.entity.Order;
import org.rohling.domain.entity.Product;
import org.rohling.domain.enums.OrderStatus;
import org.rohling.domain.repository.ClientRepository;
import org.rohling.domain.repository.ItemOrderRepository;
import org.rohling.domain.repository.OrderRepository;
import org.rohling.domain.repository.ProductRepository;
import org.rohling.exception.BusinessRuleException;
import org.rohling.exception.OrderNotFoundException;
import org.rohling.rest.dto.ItemOrderDTO;
import org.rohling.rest.dto.OrderDTO;
import org.rohling.service.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;

@Service
public class OrderServiceImplementation implements OrderService {

    @Autowired
    private OrderRepository orderRepository;

    @Autowired
    private ClientRepository clientRepository;

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private ItemOrderRepository itemOrderRepository;

    @Override
    @Transactional
    public Order save(OrderDTO dto) {
        Client client = clientRepository.findById(dto.getClient()).orElseThrow(() ->
                        new BusinessRuleException("Invalid Client ID"));

        Order order = new Order();
        order.setPrice(dto.getPrice());
        order.setOrderDate(LocalDate.now());
        order.setClient(client);
        order.setStatus(OrderStatus.COMPLETED);

        List<ItemOrder> itens = convertItens(order, dto.getItens());

        orderRepository.save(order);
        itemOrderRepository.saveAll(itens);

        order.setItens(itens);
        return order;
    }

    private List<ItemOrder> convertItens(Order order, List<ItemOrderDTO> itens) {
        if(itens.isEmpty()) {
            throw new BusinessRuleException("List of Orders is Empty.");
        }

        return itens.stream().map(dto -> {
            Product product = productRepository.findById(dto.getProduct()).orElseThrow(() ->
                    new BusinessRuleException("Invalid Product ID: ".concat(dto.getProduct().toString())));

            ItemOrder itemOrder = new ItemOrder();
            itemOrder.setAmount(dto.getAmount());
            itemOrder.setOrder(order);
            itemOrder.setProduct(product);

            return itemOrder;
        }).collect(Collectors.toList());
    }

    @Override
    public Optional<Order> getCompleteOrder(Integer id) {
        return orderRepository.findByIdFetchItens(id);
    }

    public List<Order> getAllOrders() {
        return orderRepository.findAll();
    }

    @Override
    @Transactional
    public void updateStatus(Integer id, OrderStatus orderStatus) {
        orderRepository.findById(id)
                .map(order -> {
                    order.setStatus(orderStatus);
                    return orderRepository.save(order);
                }).orElseThrow(() -> new OrderNotFoundException());
    }
}
