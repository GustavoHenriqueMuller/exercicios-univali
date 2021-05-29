package org.rohling.rest.controller;

import org.rohling.domain.entity.ItemOrder;
import org.rohling.domain.entity.Order;
import org.rohling.domain.enums.OrderStatus;
import org.rohling.rest.dto.ItemOrderInformationsDTO;
import org.rohling.rest.dto.OrderDTO;
import org.rohling.rest.dto.OrderInformationsDTO;
import org.rohling.rest.dto.OrderStatusUpdateDTO;
import org.rohling.service.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.util.CollectionUtils;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;

import javax.validation.Valid;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import static org.springframework.http.HttpStatus.*;

@RestController
@RequestMapping("/api/orders")
public class OrderController {

    @Autowired
    private OrderService orderService;

    @PostMapping
    @ResponseStatus(CREATED)
    public Integer save(@RequestBody @Valid OrderDTO dto) {
        Order order = orderService.save(dto);
        return order.getId();
    }

    @GetMapping("{id}")
    public OrderInformationsDTO getById(@PathVariable Integer id) {
        return  orderService.getCompleteOrder(id).map(o -> convert(o))
                .orElseThrow(() -> new ResponseStatusException(NOT_FOUND, "Order Not Found"));
    }

    @GetMapping
    public List<Order> getAllOrders() {
        return orderService.getAllOrders();
    }

    @PatchMapping("{id}")
    @ResponseStatus(NO_CONTENT)
    public void updateStatus(@PathVariable Integer id, @RequestBody OrderStatusUpdateDTO dto) {
        orderService.updateStatus(id, OrderStatus.valueOf(dto.getNewStatus()));
    }

    private OrderInformationsDTO convert(Order order) {
        return  OrderInformationsDTO.builder()
                .id(order.getId())
                .orderDate(order.getOrderDate())
                .price(order.getPrice())
                .clientName(order.getClient().getName())
                .status(order.getStatus().name())
                .itens(convert(order.getItens()))
                .build();

    }

    private List<ItemOrderInformationsDTO> convert(List<ItemOrder> itens) {
        if(CollectionUtils.isEmpty(itens)) {
            return Collections.emptyList();
        }

        return  itens.stream().map(item -> ItemOrderInformationsDTO.builder()
                .description(item.getProduct().getDescription())
                .price(item.getProduct().getPrice())
                .amount(item.getAmount())
                .build()).collect(Collectors.toList());
    }
}
