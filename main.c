#include <stdio.h>
#include <string.h>

/*Criado por: Guilherme Cordeiro Peixoto
 *Estudante de Engenharia de Computação
 *Centro Universitátio SENAC.
 */

int main(void) {
//Definindo o número de categorias e de itens.
  int num_cat, num_itens;
  
//Definindo contador de categorias, itens e auxiliares.  
  int tot_cat, tot_itens = 0, i = 0, x = 0, y = 0,z = 0, cont;

//Variáveis de informações de itens.  
  char nome_cat[num_cat][26], nome_item[16];
  char uni_med[4], uni_mon[3];
  double qtd[num_itens], val_unit[num_itens];
 
//Variáveis para pagamento.
  char tipo_pag;
  double desc, tot_desc, total_item[x], total_cat[11], total = 0,  tot_pag, min_parc, val_parc;
  int num_par;
  char *item[15];


//Recebe a quantidade de categorias.
  scanf("%d", &num_cat);

  for(i = 0; i < num_cat; i++){

//Recebe o nome da categoria.
    scanf("%s", nome_cat[i]);

//Recebe a quantidade de itens na categoria.
    scanf("%d", &num_itens);

//Recebe as informações sobre os itens.
    for(int x = 0; x < num_itens; x++ ) {
      scanf("%s %lf %s %s %lf", nome_item, &qtd[x], uni_med, uni_mon, &val_unit[x]);
      item[tot_itens] = nome_item;

/*Multiplica o valor unitário do item x pela quantidade
 *de itens e atribui ao total da categoria (total_item).
 */    
      total_cat[i] = 0;
      total_item[x] = val_unit[x] * qtd[x];
      total_cat[i]  = total_cat[i] + total_item[x];

/*Insere a cada ciclo o número de itens a tot_itens, que 
 *soma o total de itens no código inteiro.
 *Realiza o mesmo para o valor total da compra total_cat.*/    
      ++tot_itens;
     
    }
     total = total + total_cat[i];
  }


//Recebe o desconto e forma de pagamento.
  scanf("%lf %c", &desc, &tipo_pag);

//Cálculo do valor total do desconto.
  tot_desc = ((total * desc) / 100);
  cont = 0;
  tot_pag = total - tot_desc;

//Disponibiliza o pagamento parcelado.
  if(tipo_pag == 'P' || tipo_pag == 'p'){
    scanf("%s %lf", uni_mon, &min_parc);
    if(total < min_parc){
      tipo_pag = 'A';
    }
    num_par = tot_pag / min_parc;
    val_parc = tot_pag / num_par;
  }




// Printa os valores finais.
  printf("\n\nGuilherme Cordeiro Peixoto\n");
  printf("guilherme.cordeiro3@hotmail.com\n\n");

    for (int y = 0; y < num_cat; y++){
      printf("%s\n", nome_cat[y]);
      for(x = 0; x < num_itens; x++){
        printf("*%s : %s %.2lf (%.1lf %s)\n", item[tot_itens], uni_mon, total_item[x],qtd[x],uni_med);
      }
    printf("** TOTAL %s: R$ %.2lf\n",nome_cat[y], total_cat[cont]);
    ++cont;
    
    }

  printf("TOTAL DE ITENS: %d \n", tot_itens);
  printf("VALOR TOTAL: R$ %.2lf\n", total);
  printf("DESCONTO: %.2lf %%\n", desc);
  printf("VALOR DO DESCONTO: R$ %.2lf\n",tot_desc);
  printf("VALOR A PAGAR: R$ %.2lf", tot_pag);
  
  if(tipo_pag == 'P' || tipo_pag == 'p'){
    printf("\nPARCELAS: %d\n", num_par);
    printf("VALOR DA PARCELA: R$ %.2lf\n", val_parc);
  }
  


  return 0;
}