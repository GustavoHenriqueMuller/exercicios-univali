package org.rohling.rest.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data @AllArgsConstructor @NoArgsConstructor
public class ItemOrderDTO {
    private Integer product;
    private Integer amount;
}
