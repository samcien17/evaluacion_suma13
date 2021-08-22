#include<stdio.h>
#include<windows.h>
void crear();
void buscar();
void eliminar();
void ver_todas();
void main()
{
    system("cls");
    printf("\t*****Banco lafise*****\n");
    printf("\t 1. crear cuenta\n");
    printf("\t 2. buscar cuentat\n");
    printf("\t 3. Eliminar cuenta\n");
    printf("\t 4. ver todas las cuentas\n");
    printf("\t 5. Exit\n");
    printf("ingrese la opcion:");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        crear();
        break;
    case 2:
        buscar();
        break;
    case 3:
        eliminar();
        break;
    case 4:
        ver_todas();
        break;
    case 5:
        exit(0);
    default:
        main();
    }
}
void crear()
{
    FILE *fp;
    fp=fopen("usuarios.txt","a+");
    system("cls");
    printf("\creando nueva cuenta");
    printf("\nnombre: ");
    char nom[20];
    scanf("%s",nom);
    printf("\ncedula: ");
    char ced[20];
    scanf("%s",ced);
    int nu_cu=1022326964;
    printf("\n#de cuenta : %d",nu_cu);
    printf("\ncorreo: ");
    char cor[20];
    scanf("%s",cor);
    printf("\n telefono: ");
    char tel[20];
    scanf("%s",tel);

    fprintf(fp,"%s %s %d %s %s \n",nom,ced,nu_cu,cor,tel);
    nu_cu++;
    fclose(fp);
    printf("\n\tpulsa cualuier tecla para continuar");
    getch();
    main();
}
void buscar()
{
    FILE *fp;
    fp=fopen("usuarios.txt","r");
    system("cls");
    printf("buscar contacto ");
    printf("introdusca nombre :");
    char nom[20];
    scanf("%s",nom);
    char nom1[20],ced[20],cor[20],tel[20];
    int nu_cu;
    while(fscanf(fp,"%s %s %d %s %s \n",nom,ced,nu_cu,cor,tel)!=EOF)
    {
        if(strcmp(nom,nom1)==0)
        {
           printf("%s %s %d %s %s \n",nom,ced,nu_cu,cor,tel);
        }
    }
    fclose(fp);
    printf("\n preciones cualquier tecla par continuar");
    getch();
    main();
}
void eliminar()
{
    FILE *fp,*fp1;
    fp=fopen("usuario.txt","r+");
    fp1=fopen("usu_temp.txt","w");
    system("cls");
    printf("eliminar");
    printf("\n\t Enter Name :-");
    char nom[20];
    scanf("%s",nom);
    char nom1[20],mob[20];
    while(fscanf(fp,"%s %s",nom1,mob)!=EOF)
    {
        if(strcmp(nom,nom1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s\n",nom,mob);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("usuario.txt","w");
    fp1=fopen("usu_temp.txt","r");
    while(fscanf(fp1,"%s %s",nom1,mob)!=EOF)
    {

        fprintf(fp,"%s %s\n",nom1,mob);
    }
    fclose(fp);
    fclose(fp1);
    remove("usu_temp.txt");
    printf("\n Pulse cuaquier tecla para continuar");
    getch();
    main();
}
void ver_todas()
{
    FILE *fp;
    fp=fopen("usuario.txt","r");
    printf(" todas las cuentas ");
    char name1[20];
    while(fscanf(fp,"%s %s",name1)!=EOF)
    {
        printf("\n\t NAME    :-  %s",name1);

    }
    fclose(fp);
    printf("\n presion cualquier tecla para continuar ");
    getch();
    main();
}
