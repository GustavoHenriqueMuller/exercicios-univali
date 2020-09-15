/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.univali.cc.prog3.banco.dominio;

/**
 *
 * @author 1978233
 */
public class Relatorio {
    public void gerarRelatorio(Imprimivel imprimivel){
        System.out.println(imprimivel.mostrarDados());
    }
}
