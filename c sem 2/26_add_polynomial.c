/* 
program for addition of two polynomials
 */
 #include<stdio.h>


 struct poly
 {
	 int coeff;
	 int expo;
 };

 struct poly poly1[10],poly2[10],poly3[10];


 int Read_poly(struct poly []);
 int Add_poly(struct poly [],struct poly [],int ,int ,struct poly []);
 void Display( struct poly [],int terms);

 int main()
 {
	int temp,temp2,temp3;

	temp=Read_poly(poly1);
	printf(" \n First polynomial : ");
	Display(poly1,temp);

	temp2=Read_poly(poly2);
	printf(" \n Second polynomial : ");
	Display(poly2,temp2);


	temp3=Add_poly(poly1,poly2,temp,temp2,poly3);
	printf(" \n\n Resultant polynomial after addition : ");
	Display(poly3,temp3);
	printf("\n");

	return 0;
 }

 int Read_poly(struct poly p[10])
 {
	int temp,i;

	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%d",&temp);

	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(i=0;i<temp;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d",&p[i].coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d",&p[i].expo);        
	}
	return(temp);
 }

 int Add_poly(struct poly poly1[10],struct poly poly2[10],int temp,int temp2,struct poly poly3[10])
 {
	int i,j,k;


	i=0;
	j=0;
	k=0;

	while(i<temp && j<temp2)
	{
		if(poly1[i].expo==poly2[j].expo)
		{
			poly3[k].coeff=poly1[i].coeff + poly2[j].coeff;
			poly3[k].expo=poly1[i].expo;

			i++;
			j++;
			k++;
		}
		else if(poly1[i].expo>poly2[j].expo)
		{
			poly3[k].coeff=poly1[i].coeff;
			poly3[k].expo=poly1[i].expo;
			i++;
			k++;
		}
		else
		{
			poly3[k].coeff=poly2[j].coeff;
			poly3[k].expo=poly2[j].expo;
			j++;
			k++;
		}
	}

	while(i<temp)
	{
		poly3[k].coeff=poly1[i].coeff;
		poly3[k].expo=poly1[i].expo;
		i++;
		k++;
	}

	while(j<temp2)
	{
		poly3[k].coeff=poly2[j].coeff;
		poly3[k].expo=poly2[j].expo;
		j++;
		k++;
	}

	return(k); 
 }

 void Display(struct poly p[10],int term)
 {
	int k;

	for(k=0;k<term-1;k++)
	printf("%d(x^%d)+",p[k].coeff,p[k].expo);
	printf("%d(x^%d)",p[term-1].coeff,p[term-1].expo);
}