#include <stdio.h>
#include <conio.h>


int isempty();
int isfull();
void insert(int,int);
int gethighestpriority();
int deletehighestpriority();
void display();

struct priorityqueue
{
    int ele;
    int priority;
}pq[5];
int rear=-1;
int main()
{
    int ch,p,ele;
    do{
        printf("\n 1.Insert \n 2.Get highest priority \n 3.Delete highest priority \n 4.Display \n 5.Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: if(isfull())
                       printf("\n Priority queue is full");
                       else{
                           printf("\n Enter element to insert: ");
                           scanf("%d",&ele);
                           printf("\n Enter priority: ");
                           scanf("%d",&p);
                           insert(ele,p);
                       }
                       break;
            case 2:   if (isempty())
                      {
                       printf("\n Priority queue is empty");
                      }
                      else
                        {
                          p=gethighestpriority();
                          printf("\n Highest priority = %d",p);
                        }
                      break;
            case 3:
                      if (isempty())
                      {
                      printf("\n Priority queue is empty");
                      }
                      else
                        {
                          ele=deletehighestpriority();
                          printf("\n %d is deleted",ele);
                        }
                      break;
            case 4: if(isempty())
                  printf("\n Priority queue is empty");
                  else {
                      display();
                  }
                    break;
                    }
                    }while(ch!=5);

           }
                    int isempty()
                    {
                        if(rear ==-1)
                        return 1;

                        else
                        return 0;
                    }

                    int isfull() {
                        if(rear==4)
                        return 1;

                        else
                        return 0;
                    }

                    void insert(int ele,int p)
                    {
                        rear=rear+1;
                        pq[rear].ele=ele;
                        pq[rear].priority=p;
                    }

                    int gethighestpriority()
                    {
                        int i,p=-1;
                        if(!isempty())
                            {
                              for(i=0;i<=rear;i++)
                                {
                                 if(pq[i].priority > p)
                                   p=pq[i].priority;
                                }
                           }
                     return p;
                    }
                    int deletehighestpriority()
                    {
                        int i,j,p,ele;
                        p=gethighestpriority();
                        for(i=0;i<=rear;i++) {
                            if(pq[i].priority==p) {
                                ele=pq[i].ele;
                                break;
                            }
                        }
                        if(i<rear)
                        {
                            for(j=i;j<rear;j++)
                                {
                                 pq[j].ele=pq[j+1].ele;
                                 pq[j].priority=pq[j+1].priority;
                                }
                        }
                        rear=rear-1;
                        return ele;
                    }

                    void display() {
                        int i;
                        printf("\n Priority queue= ");
                        for(i=0;i<=rear;i++)
                         printf("ele = %d - priority = %d",pq[i].ele,pq[i].priority);
                    }
