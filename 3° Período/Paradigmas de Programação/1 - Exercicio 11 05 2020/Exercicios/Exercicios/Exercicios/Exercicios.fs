open System

let diasParaAnos dias =
    dias/365
let diasParaMeses dias =
    dias/30
let diasParaTempo dias =
    printfn "EXERCICIO 2: %d dias: Anos: %d, Meses: %d, Dias: %d %s" dias (diasParaAnos dias) (diasParaMeses(dias - (diasParaAnos dias * 365))) (dias - (((diasParaAnos dias) * 365) + (diasParaMeses(dias - (diasParaAnos dias * 365))) * 30)) "\n "
let tempoEmDias anos meses dias = 
    anos * 365 + meses * 30 + dias
let mediaPonderada val1 val2 val3 =
    ((val1 * 2.0) + (val2 * 3.0) + (val3 * 5.0))/(2.0 + 3.0 + 5.0)
let max val1 val2 =
    if val1 > val2 then
        val1
    else
        val2
let positivo val1 =
    if val1 > 0 then true else false
let par val1 =
    if val1 % 2 = 0 then true else false
let tipoTriangulo lado1 lado2 lado3 =
    if (lado1 > lado2 + lado3 || lado2 > lado1 + lado3 || lado3 > lado1 + lado2) then "Não forma triângulo"
    elif (lado1 = lado2 && lado2 = lado3) then "Equilátero"
    elif (lado1 = lado2 || lado1 = lado3 || lado2 = lado3) then "Isósceles"
    else "Escaleno"
let somaHorarios segundos1 minutos1 horas1 segundos2 minutos2 horas2 =
    let somaSegundos() =
        segundos1 + segundos2

    let somaMinutos() =
        minutos1 + minutos2 + (somaSegundos() % 60)

    let somaHoras() =
        horas1 + horas2 + (somaMinutos() % 60)

    string (somaHoras() % 24) + ":" + string (somaMinutos() % 60) + ":" + string (somaSegundos() % 60)
let anoEBissexto ano =
    let checagem4Anos =
        ano % 4 = 0
    let checagem100Anos =
        ano % 100 = 0
    let checagem400Anos = 
        ano % 400 = 0

    if checagem400Anos then
        true
    else
        if checagem100Anos then            
            false
        else
            if checagem4Anos then
                true
            else
                false

[<EntryPoint>]
let main argv =
    printfn "\nEXERCICIO 1: Dias desde que nasci: %d %s" (tempoEmDias 18 2 11) "\n"
    diasParaTempo 6000
    printfn "EXERCICIO 3: Media ponderada: 9, 8, 2: %f %s" (mediaPonderada 9.0 8.0 2.0) "\n"
    printfn "EXERCICIO 4: Maior Valor: 4, 10: %d %s" (max 4 10) "\n"
    printfn "EXERCICIO 5: Número -4: É positivo: %b, É par: %b %s" (positivo -4) (par -4) "\n"
    printfn "EXERCICIO 6: Medidas 3, 4, 5: %s %s" (tipoTriangulo 3 4 5) "\n"
    printfn "EXERCICIO 7: Soma (20:53:30) + (6:45:30) = %s %s" (somaHorarios 30 53 20 30 45 6) "\n"
    printfn "EXERCICIO 8: Ano é bissexto (2024) = %b %s" (anoEBissexto 2024) "\n"
    0