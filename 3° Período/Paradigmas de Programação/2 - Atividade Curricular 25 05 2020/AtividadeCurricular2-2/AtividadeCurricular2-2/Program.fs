open System

// Fazer uma função que a partir de um vetor [0..20] e faça o seguinte processo:
// a. Primeiro filtre os valores para deixar somente ímpares do vetor (List.filter)
// b. Depois multiplique cada valor por 2 (List.map)
// c. Por último filtre novamente os valores, agora para deixar somente os múltiplos de 3.
let questao1 lista =
    let somenteImpar numero =
        numero % 2 <> 0
    let multiplica2 numero =
        numero * 2
    let somenteMultiplo3 numero =
        numero % 3 = 0

    List.filter somenteImpar lista |> List.map multiplica2 |> List.filter somenteMultiplo3

// Faça uma função que receba 2 valores, caso seja iguais, multiplique os dois, caso
// sejam diferente, faça o primeiro valor elevado ao segundo.
let questao2 numero1 numero2 =
    let rec potencia num1 num2 =
        match num2 with
        | 1 -> num1
        | _ -> num1 * potencia num1 (num2-1)

    match numero1 with
    | _ when numero1 = numero2 -> numero1 * numero2
    | _ -> potencia numero1 numero2

// Implementar uma função que receba uma lista como parâmetro e retorne o produto de todos os elementos. 
let questao3 lista =
    let rec multiplicacaoLista lista =        
        match lista with
        | head :: tail -> head * multiplicacaoLista tail
        | [] -> 1

    multiplicacaoLista lista

// Faça uma função que receba um valor e determine se ele é primo ou não.
let questao4 numero =
    let numeroOriginal = numero

    let rec isPrimo numero =        
        match numero with
        | 1 -> true
        | _ when numero <> numeroOriginal & (numeroOriginal % numero) = 0 -> false        
        | _ when numero <> 1 -> isPrimo (numero-1)        

    isPrimo numeroOriginal

[<EntryPoint>]
let main argv =
    let minhaLista = [1..20]

    printfn "Questão 1 (números de 1 à 20): %A" (questao1 minhaLista)
    printfn "Questão 2 (números 2 e 3): %d" (questao2 2 4)
    printfn "Questão 3 (números de 1 à 20): %d" (questao3 minhaLista)
    printfn "Questão 4 (número 11): %b" (questao4 11)

    0
