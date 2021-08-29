package org.rohling.rest.dto;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class OrderInformationsDTO {
    private Integer id;
    private String clientName;
    private BigDecimal price;
    private LocalDate orderDate;
    private String status;
    private List<ItemOrderInformationsDTO> itens;
}
