#include<stdio.h>
#include<string.h>

char uprod[30];
int quantity;
char pname[30];
int price;
int fat;
char name[30];
long long mob;
void customer()
{
	printf("Enter name and mobils");
	scanf("%s%ld",&name,&mob);
}
void addproduct()
{
	
	FILE*fp;
	fp=fopen("product.txt","a");
	printf("enter productname and price");
	scanf("%s%d",&pname,&price);
	fprintf(fp,"%s\t%d\n",pname,price);
	fclose(fp);
	
}
int showprice(char uprod[])
{
		FILE*fp;
	fp=fopen("product.txt","r");
	while(1){
		fscanf(fp,"%s%d",&pname,&price);
		if(feof(fp))
		{
			break;
		}
		if(strcmp(pname,uprod)==0)
		{
			return price;
		}
		//printf("%s\t %s \n",pname,price);
	}
	fclose(fp);
}
void order()
{
	FILE*fp;
	fp=fopen("product.txt","r");
	while(1){
		fscanf(fp,"%s%d",&pname,&price);
		if(feof(fp))
		{
			break;
		}
		printf("%s\t %d \n",pname,price);
	}
	printf("Enter Product name and quantity");
	scanf("%s %d",&uprod,&quantity);
	price=showprice(uprod);
	printf("Price Of Product is %d",quantity*price);
	saveorder(uprod,quantity*price);
	
}
void saveorder(char uprod[],int fat)
{
	FILE*fp;
	fp=fopen("bill.txt","a");
	fprintf(fp,"%s\t%ld\t%s\t%d\n",name,mob,uprod,fat);
	fclose(fp);
}
void showallbill()
{
	FILE*fp;
	fp=fopen("bill.txt","r");
	while(1){
		fscanf(fp,"%s%ld%s%d",&name,&mob,&uprod,&fat);
	if(feof(fp)){
	break;
	}
	printf("%s\t%ld\t%s\t%d\n",name,mob,uprod,fat);
}
fclose(fp);
}

void showmobilebill()
{
	FILE*fp;
	long long m;
	int sum=0;
	printf("enter your mobile number");
	scanf("%ld",&m);
	fp=fopen("bill.txt","r");
	while(1){
		fscanf(fp,"%s%ld%s%d",&name,&mob,&uprod,&fat);
	if(feof(fp)){
	break;
	}
	
	if(m==mob){
		printf("%s\t%ld\t%s\t%d\n",name,mob,uprod,fat);
	
	sum = sum+fat;	
		}
}
printf("total amout is : %d",sum);
fclose(fp);
}

int main()
{
	int ch;
	printf("press 1 for admin  press 2 for order");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("press 1 to add new product\n");
		printf("press 2 to View All Bill \n");
		printf("press 3 to Bill By Mobile no \n");
		scanf("%d",&ch);
		if(ch==1)
		{
			do{
				addproduct();
				printf("Are you want to continue press 1");
				scanf("%d",&ch);
			}
			while(ch==1);
		}
		if(ch==2)
		{
			showallbill();
		}
		if(ch==3)
		{
			showmobilebill();
		}
	}
	else if(ch==2)
	{
		printf("press 1 to order food");
		scanf("%d",&ch);
		if(ch==1)
		{
			customer();
			do{
				order();
				printf("Are you want to continue order press 1");
				scanf("%d",&ch);
			}
			while(ch==1);
			
		}
	}
}
