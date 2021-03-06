#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"node.h"


void quiz_list(node *p,node *t,int num,int cha[]){
  int ques=0,dt;
  int i,j,rate=0,per=0,qt;
  char ans[30];
  time_t start,rap;
  printf("この機能は連結リストに登録した問題をランダムに出題できる機能です\n出題する問題数を指定してください（連結リストの数より上の数は指定できません）\n");
  printf("現在の連結リストの数 %d個\n",num);
  scanf("%d",&ques);
  if(ques>num){
    printf("その数は指定できません\n");
  }
  printf("一問あたりの時間を決めてください（単位：秒）\n");
  scanf("%d",&qt);
  
  time(&start);
  for(i=0;i<ques;i++){
    p=t;
    for(j=0;j<cha[i];j++){
      p=p->next;
    }
    printf("%s\t",p->jpn);
    scanf("%s",ans);
    if(strcmp(p->eng,ans)==0){
      rate++;
    }
    time(&rap);
    dt=difftime(rap,start);
    if(dt>(i*qt)){
      printf("時間切れです\n");
      goto end;
    }
    
  }
 end:
  printf("結果発表\n");
  printf("経過時間 %d秒\n",dt);
  printf("正答数 %d\n",rate);
  per=((double)rate/ques)*100;
  printf("正答率 %d％\n",per);
  if(per==100){
    printf("この調子で頑張りましょう！\n");
  }else{
    printf("あともうちょっとです・・・\n");
  }
  return ;
}

  void random_number(int cha[],int num){
    int i,j,a=0,rad;
    for(i=0;i<num;i++){
      cha[i]=i;
    }
    printf("\n");
    srand(time(NULL));
    for(i=0;i<num-1;i++){
      for(j=i+1;j<num;j++){
	rad=rand()%1000;
      if(rad<500){
	a=cha[i];
	cha[i]=cha[j];
	cha[j]=a;
      }
      }
    }
    return;
  }
  
  int count_list(node* init){
    int count=0;
    while(init!=NULL){
      init=init->next;
      count++;
  }
    
  return count;
  }
  
  void random_list(node* init){
    int num;
    if(!init->next){
      printf("連結リストが存在しません\n");
      return;
    }else{
      num=count_list(init->next);
      int cha[num];
      random_number(cha,num);
      quiz_list(init->next,init->next,num,cha);
    }
    
    return;
  
  }
