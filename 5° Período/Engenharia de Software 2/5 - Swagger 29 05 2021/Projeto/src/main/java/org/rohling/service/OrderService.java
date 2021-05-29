package org.rohling.service;

import org.rohling.domain.entity.Order;
import org.rohling.domain.enums.OrderStatus;
import org.rohling.rest.dto.OrderDTO;

import java.util.List;
import java.util.Optional;

public interface OrderService {
    Order save(OrderDTO dto);
    Optional<Order> getCompleteOrder(Integer id);
    List<Order> getAllOrders();
    void updateStatus(Integer id, OrderStatus orderStatus);
}
