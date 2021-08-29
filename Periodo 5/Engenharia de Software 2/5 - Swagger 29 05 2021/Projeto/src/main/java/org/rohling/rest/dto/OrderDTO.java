package org.rohling.rest.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.rohling.validation.NotEmptyList;

import javax.validation.constraints.NotNull;
import java.math.BigDecimal;
import java.util.List;

@Data @AllArgsConstructor @NoArgsConstructor
public class OrderDTO {
    @NotNull(message = "{field.clientId.required}")
    private Integer client;

    @NotNull(message = "{field.orderPrice.required}")
    private BigDecimal price;

    @NotEmptyList(message = "{field.orderItens.required}")
    private List<ItemOrderDTO> itens;
}
