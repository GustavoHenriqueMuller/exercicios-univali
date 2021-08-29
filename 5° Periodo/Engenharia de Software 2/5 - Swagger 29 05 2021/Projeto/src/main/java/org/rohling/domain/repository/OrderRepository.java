package org.rohling.domain.repository;

import org.rohling.domain.entity.Client;
import org.rohling.domain.entity.Order;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;
import java.util.Optional;

public interface OrderRepository extends JpaRepository<Order, Integer> {
    List<Order> findAllByClient(Client client);

    @Query("SELECT o FROM Order o LEFT JOIN FETCH o.itens WHERE o.id = :id")
    Optional<Order> findByIdFetchItens(@Param("id") Integer id);
}
