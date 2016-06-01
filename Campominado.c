#include <stdio.h>
#include <stdlib.h>
#include <time.h>


   // int v,j,i;
int bomb_vet[10]; // vetor que guarda as posicoes das bombas
int q=0; int i = 0; int x = 0; int j = 0; int v = 1; int c = 0; int l = 0;
int minefield[8][8]; // [linha][coluna]
int vis_mine[8][8]; // matriz de visibilidade
int bomb_counter = 0;
int  user_line;
int  user_column;
int end_game = 0; // quando for 1 o jogo acabou

int pick_line[64] ;  //  vetor com o historico de  escolhas (linhas) 
int pick_column[64] ;  //  vetor com o historico de  escolhas (colunas) 
int qt_picks = 0; // quantidade de escolhas
int index_picks = 0;
   
void main (){



      void bomb_generator(){
            srand(time(NULL));

      // int v,i,j,x;
      // parte da geracao e verificacao das posicoes das bombas
            while(v !=0){ // vai ser repetido ate que as 10 posicoes geraldas sejam diferentes
       
         // geracao das 10 posicoes das bombas utilizando o rand com o seed (time)
                  v = 0;
                  for(i=0 ; i < 10 ; i++) {
            
                  bomb_vet[i]= rand()%78;
               // printf("Posicao da bomba %d : %d\n",i, bomb_vet[i]);  
               // printf("linha da Posicao : %d\n", ((bomb_vet[i]/10) * 1));
               // printf("coluna da Posicao : %d\n", bomb_vet[i]%10);
               // printf("\n");
          
                  }
               // verificacao das posicoes das bombas, se duas ou mais posicoes forem iguais, o valor de V vai ser alterado.
               // a posicao 0 e comparada com 1,2,3,4,5,6,7,8,9
               // a posicao 1 e comparada com 2,3,4,5,6,7,8,9
               // e assim sucessivamente
                  for (x = 0; x < 9; x++){

                        for (j = x+1; j < 10; j++){

                  //printf("%d \n", bomb_vet[x]);
                  //printf("%d \n", bomb_vet[j]);
                              if (bomb_vet[x] == bomb_vet[j]){
                                    v++;
                              }
                        }
                  }  

                  x = 0;

            // esse for verifica se a coluna da posição da bomba é maior que 7, se for maior que 7 não valida as posições pq a matriz só possui 7 colunas.
                  for (x; x < 10 ; x++){

                        if (bomb_vet[x]%10 > 7){
                              v++;
                        } 
                  }

            // printf("valor de v: %d\n", v);
            // printf("Tamanho do vetor: %ld\n",sizeof(bomb_vet)/sizeof(int) );

            }
      }

      void vis_mine_filler(){
      // int l,c;
            for (l = 0 ; l < 8 ; l++){ // inicialmente a matriz é preenchida com 0 - sem visibilidade

                  for(c = 0 ; c < 8 ; c++ ){ 
                        vis_mine[l][c] =0;
                  }
            }
      }

      void minefield_filler(){

      // int l, c; 
      // preenchimento da matriz com 0 para depois sobrescrever com 9 se tiver bomba
            for (l = 0 ; l < 8 ; l++){ 

                  for(c = 0 ; c < 8 ; c++ ){ 
                        minefield[l][c] = 0;
                  }
            }

         //  preechimento da matriz com as bombas, lugares com bombas sao indicados com numero 9...lugar sem bomba com o numero 0

      // int q;
            int teste = 0;
            for (l = 0 ; l < 8 ; l++){

                  for(c = 0 ; c < 8 ; c++ ){

                        for(q = 0 ; q < 10 ; q++){

                     // printf("%d\n",bomb_vet[q] );  
                              if ( (l  == (bomb_vet[q]/10) )  && ( (c == (bomb_vet[q]%10) ) ) ) {

                                    minefield[l][c] = 9;
                                    bomb_counter++;
                                    // printf("linha %d e coluna %d, valor: %d \n",l,c,minefield[l][c]);
                              }
                     // else{
                     //       minefield[l][c] = 0;

                     //    // printf("linha %d e coluna %d, valor: %d \n",l,c,minefield[l][c]);
                     // }
                     // printf("%d\n", minefield[l][c]);
                        }
                  // i++;
                  }
            }
      // printf("Numero de bombas: %d\n",bomb_counter );
            printf("\n\n");
      }

     void show_mine(){


      // printf("Campo minado \n");
         // int l,c;
            printf("  \t0\t1\t2\t3\t4\t5\t6\t7 \n");
            printf("\n");
            for (l = 0 ; l < 8 ; l++){ // exibição do campo

                  printf(" %d\t", l);
                  for(c = 0 ; c < 8 ; c++ ){

            // printf("linha: %d, coluna: %d, %d\n",l,c,minefield[l][c] );
                        if(vis_mine[l][c] == 0){
               // printf("%d ",c );
                              printf("--\t ");
                        }
                        else{

               // printf("%d ",c );
                        printf("%d\t",minefield[l][c]);

                        }
                  }
                  printf("\n\n");
            }
      }

// printf("teste\n");

      void field_checker(int field_line, int field_column ){

            // int check = 0;
            if (  minefield [field_line][field_column] != 9 ) {

                  if (  (field_line - 1 >= 0)  && (field_column - 1 >= 0) ) {

                        if ( minefield[field_line -1][field_column - 1]  == 0) {
                              vis_mine[field_line - 1][field_column - 1] = 1;
                        }
                  }

                  if ( field_column - 1 >= 0) {

                        if (minefield[field_line][field_column - 1]  == 0) {
                              vis_mine[field_line][field_column - 1] = 1;
                        }
                  }

                  if ( ( field_line + 1 <= 7) && ( field_column -1 >=0) ) {
                        if (  minefield[field_line + 1][field_column - 1] == 0 ){
                              vis_mine[field_line + 1][field_column - 1]  = 1;
                         }
                  }

                  if ( field_line - 1 >= 0 ){
                        if ( minefield[field_line - 1][field_column]  == 0 ) {
                              vis_mine[field_line - 1][field_column] = 1;
                        }     
                  }

                  if ( field_line + 1  <= 7) {
                        if ( minefield[field_line + 1][field_column] == 0 ){
                              vis_mine[field_line + 1][field_column] = 1;
                        }
                  }
                  if ( ( field_line - 1 >= 0) && ( field_column + 1 <= 7 )  ) {
                        if ( minefield[field_line - 1][field_column + 1] == 0 ){
                              vis_mine[field_line - 1][field_column + 1] = 1 ;
                        }
                  }

                  if ( field_column + 1 <= 7) {
                        if ( minefield[field_line][field_column + 1] == 0){
                              vis_mine[field_line][field_column + 1] = 1;
                        }
                  }

                  if ( (field_line + 1 <= 7)  && ( field_column + 1 <= 7 ) ) {
                        if ( minefield[field_line + 1][field_column + 1]  == 0){
                              vis_mine[field_line + 1][field_column + 1] = 1;
                        }
                  }
            } 

      }
      void show_game(){

            int verify_line = 1;
            int verify_column = 1;
            int verify_pick = 1;

            while (verify_pick == 1 ) {
                  verify_pick = 0;
                  while  (verify_line == 1){
                        printf("Escolha a linha: ");
                        scanf("%d" , &user_line);

                        if (user_line < 0 || user_line >7){
                              printf("Favor escolher numero entre 0 e 7.\n");  
                        }
                        else{
                              verify_line = 0;
                        }
                  }

                  while (verify_column == 1){
                        printf("Escolha a coluna: ");
                        scanf("%d" , &user_column);

                        if (user_column < 0 || user_column >7){
                              printf("Favor escolher numero entre 0 e 7.\n");  
                        }
                        else{
                              verify_column = 0;
                        }

                  }
                  // verify_pick = 0;
                  if ( qt_picks > 0) {
                              for ( i = 0 ; i < qt_picks; i++ ){
                                                // printf("%d\t%d\n\n",pick_line[i],pick_column[i] );
                              if ( (pick_line[i] == user_line) && (pick_column[i] == user_column  ) ) {
                                     verify_pick =1;
                                    // printf("Essa posicao ja foi esclhida\n");
                              }
                              // else{
                              //       verify_pick = 0;
                              // }

                        }
                  }
                  else{
                        verify_pick =0;
                  }
                  if  ( verify_pick == 1) {
                                                            printf("Essa posicao ja foi esclhida\n"); 
                  }
                  if (verify_line == 0 && verify_column == 0 && verify_pick == 0){
                        qt_picks++;
                        index_picks = qt_picks - 1; //  indice dos vetores de picks os picks serao listados nos vetores...primeira escolha pick_line[0], pick_column[0] e assim sucessivamente
                        // verify_pick = 0;
                        pick_line[index_picks] =user_line;
                        pick_column[index_picks] = user_column;
                        field_checker(user_line,user_column);
                        // picklist(user_line,user_column,index_picks);
                  }
                  verify_line  = 1 ;
                  verify_column = 1;

                  // printf("%d\n",qt_picks );
            }

            // printf("-------\n");
            // printf("%d\n", user_line);

            // printf("%d\n", user_column);

            // printf("%d\n", qt_picks);
            vis_mine[user_line][user_column] = 1;

            if (minefield[user_line][user_column] == 9){
                  end_game=1;
            }

            
            show_mine();
            // for (i = 0 ; i < qt_picks ; i++){
            //       printf("%d\t%d\n",pick_line[i],pick_column[i] );
            // }
      }

      void game_over(){
      
            printf("--------------------------------------------\n");
            printf("Game Over.\n");
            printf("--------------------------------------------\n");

      }



   bomb_generator();
   vis_mine_filler();
   minefield_filler();
   show_mine();

   while (end_game == 0){
      show_game();
   }

   if (end_game != 0 ){
         game_over();
   }



}
