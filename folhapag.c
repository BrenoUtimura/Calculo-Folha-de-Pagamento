#include <stdio.h>

int main(void)
{
    int num, horastrabextra, dias, horasfimsemanal, domingos, diasmes;
    float salario, horas, horatrab, horasextras, salariofim, semanal, mescheio, fgts;
    float faixa, f1, f2, f3, f4;
    int resposta1, resposta2;
    
    printf("Digite o que você deseja calcular hoje?\n\n");
    printf("1-Calcular Horas Trabalhadas\n");
    printf("2-Calcular Horas Mensais\n");
    printf("3-Calcular Horas Extras\n");
    printf("4-Calcular INSS\n");
    printf("5-Calcular FGTS\n");
    scanf("%d", &num);
    
    
    
    /* 1-Calcular Horas Trabalhadas */
    if(num == 1){
        printf("Informe o salário do Funcionário: R$ ");
        scanf("%f", &salario);
        
        printf("Informe a quantidade de Horas Mensais:  ");
        scanf("%f", &horas);
        
        if(salario <= 0 || horas <= 0){
            
            printf("Os valores não podem ser dessa forma, digite os valores corretos!!");            
        }
        else{
            
            horatrab = salario / horas;
        
            printf("A quantidade por hora trabalhada é: R$ %.2f", horatrab);   
        }
        
    }
    else {
        
        /* 2-Calcular Horas Mensais e Semanais */
        if (num == 2){
            
            printf("Quantos dias ele trabalha dutantes a semana? ");
            scanf("%d", &dias);
            
            printf("Quantas horas ele trabalha por dia? ");
            scanf("%f", &horas);
            
            
            /* Condição para quem trabalha 6 dias mesmo */
            if (dias == 6){
                printf("Quantos domingos tem nesse mês calculado?  ");
                scanf("%d", &domingos);
                
                printf("Quantos dias tem nesse mês calculado?  ");
                scanf("%d", &diasmes);
                
                diasmes = diasmes - domingos;
                semanal = horas * dias;
                mescheio = semanal * diasmes;
                mescheio = mescheio / diasmes;
                
                printf("A quantidade de dias trabalhados na semana é: %.0f \n", semanal);
                printf("A quantidade de dias trabalhados no mês é: %.0f\n", mescheio);
                
                return 0;
            }
            
            /* Condição para quem trabalha menos de 6 dias */
            printf("Pode responder essa pergunta digite 1 para 'sim' ou 2 para 'nao'\n");
            printf("O funcionário trabalha aos sábados?  ");
            scanf("%d", &resposta1);
            
            if(resposta1 == 1){
                
                printf("Quantas horas ele faz aos sábados?  ");
                scanf("%d", &horasfimsemanal);
            }
            
            semanal = (horas * dias) + horasfimsemanal;
            mescheio = semanal * 5;  /* São 5 semanas no mês de acordo com o calendário comercial */
            
            printf("A quantidade de horas semanais do trabalhador é:  %.2f \n", semanal);
            printf("A quantidade de horas mensais do trabalhador é:   %.2f", mescheio);
        }
        else{

            /* 3-Calcular Horas Extras */
            if(num == 3){
                
                printf("Informe o salário do Funcionário: R$ ");
                scanf("%f", &salario);
                    
                printf("Informe a quantidade de Horas Mensais:  ");
                scanf("%f", &horas);
                
                printf("Informe a porcentagem de Horas Extras que você gostaria:  ");
                scanf("%f", &horasextras);
                
                printf("Informe a quantidade de Horas Extras Trabalhadas:  ");
                scanf("%d", &horastrabextra);
                
                if(salario <= 0 || horas <= 0 || horasextras <= 0 || horastrabextra <= 0){
                    
                    printf("Os valores não podem ser dessa forma, digite os valores corretos!!");            
                }
                else{
                    
                    /* Cálculo das horas extras */
                    horasextras = (horasextras / 100) + 1;    
                    horatrab = salario / horas;
                    horasextras = horatrab * horasextras;
                    horasextras = horasextras * horastrabextra;
                    
                    /* A soma do salário com o valor de horas extras */
                    salariofim = salario + horasextras;
                
                    printf("A quantidade por hora trabalhada é: R$ %.2f  \n", horasextras);
                    printf("Esse valor das horas extras somadas com o salário ficaria dessa forma: R$ %.2f", salariofim);
                }
                    
            }
        }
        
    }

    /* Calcular valor de desconto de INSS do funcionário */
    if(num == 4){

        printf("Esse cálculo é de acordo com a aliquota do INSS de 2024!!\n");
        printf("Informe o salário do Funcionário:  R$ ");
        scanf("%f", &salario);

        /* Verifica em qual faixa salarial se encontra */
        /* Lembrando que é referente a tabela do INSS 2024 */
        if(salario <= 1412){
            f1 = salario * 0.075;
            faixa = f1;
        }
        else{
            if(salario >= 1412.01 && salario <= 2666.68){
                f1 = 1412 * 0.075;
                f2 = (salario - 1412) * 0.09;
                faixa = f1 + f2;
            }
            else{
                if(salario >= 2666.69 && salario <= 4000.03){
                    f1 = 1412 * 0.075;
                    f2 = 2666.68 * 0.09;
                    f3 = (salario - 2666.69) * 0.12;
                    faixa = f1 + f2 + f3;
                }
                else{
                    /* Aqui na última faixa ele cosidera este cálculo do valor 4000.04 pra frente */
                    if(salario >= 4000.04){
                        f1 = 1412 * 0.075;
                        f2 = 2666.68 * 0.09;
                        f3 = 4000.03 * 0.12;
                        f4 = (salario - 4000.03) * 0.14;
                        faixa = f1 + f2 + f3 + f4;
                    }
                }
            }
        }

        salario = salario - faixa;

        printf("\nO valor de desconto do INSS será de:  R$ %.2f\n", faixa);
        printf("O seu salário após o desconto irá ficar:  R$ %.2f\n", salario);
        
    }

    /* Calcular o valor de FGTS para o funcionário */
    if(num == 5){

        printf("Informe o salário do funcionário:  ");
        scanf("%f", &salario);

        printf("Pode responder essa pergunta digite 1 para 'sim' ou 2 para 'nao'\n");
        printf("O funcionário é doméstica?  ");
        scanf("%d", &resposta1);

        printf("O funcionário é jovem aprendiz?  ");
        scanf("%d", &resposta2);

        /* Verifica se é doméstica */
        if(resposta1 == 1){
            fgts = salario * 0.11;
        }

        /* Verifica se é jovem aprendiz e se não for ele calcula os 8% normal mesmo */
        if(resposta2 == 1){
            fgts = salario * 0.03;
        }
        else {
            fgts = salario * 0.08;
        }

        printf("O valor do seu FGTS de acordo com o salário é de:  %.2f", fgts);

    }
    

    return 0;
}
