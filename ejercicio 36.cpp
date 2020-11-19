#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    char nombre[30];
    char apellido [30];
    char edad;
    long tel;
    char email [50];

} datos_t;



struct lista{
    datos_t inf;
    struct lista *l;
};

typedef enum {
    l_sin_inf = 0,
    l_con_inf = 1,
} lista_t;


int main (){
    FILE *fp;
    datos_t bf;
    char a[30];
	char b[30];
    struct lista *p=NULL, *u=NULL, *aux, *r, *aux2;
    int i=0;
    lista_t k;

    if ((fp=fopen ("contactos.dat", "rb"))==0){
        printf("\nNo existe archivo contactos.dat\n");
    }else{
    
        fread (&bf, sizeof (datos_t),1, fp);
        while (!feof (fp)){
            aux = (struct lista *)malloc(sizeof (struct lista));
            aux->inf=bf;
            
            if (p==NULL) k=0;
            else k=1;
            
            
            switch(k){
                case l_sin_inf:
                
                    aux->l=NULL;
                    p=u=aux;
                    
                break;

                case l_con_inf:
                    
                    strcpy (a, p->inf.apellido);
                    strcpy (b, aux->inf.apellido);
                                       
                    if (strcmp (a,b)>0){
                        aux->l=p;
                        p=aux;
                    } else{
                        r=p;
                        strcpy (a, r->l->inf.apellido);
                        while (r->l && strcmp (a,b)<0){
                            
                            r=r->l;
                           
                        }
                        if (r==u){
                            aux->l=NULL;
                            r->l=aux;
                            r=aux;
                            
                        }else
                        {
                            aux->l=r->l;
                            r->l=aux;
                        }
                        
                    }
                    
                    break;

            }
            
            aux= NULL;
            free (aux);
            fread (&bf, sizeof (datos_t),1, fp);
            
        }
        fclose (fp);
    }
    if ((fp = fopen ("contactos_ordenados.dat", "wb"))==NULL){
        printf ("\nNo se pudo crear el archivo contactos_ordenados.dat");
    }else
    {
        aux = (struct lista *)malloc (sizeof(struct lista));
        while (p){
            
            bf = p->inf;
            bf.id = i + 1;
            fwrite (&bf, sizeof (datos_t), 1, fp);
            printf ("\nDatos guardados en ""contactos_ordenados.dat"":");
            printf ("\n %d - %s, %s - Tel: %ld - Edad: %d - Mail: %s\n", bf.id, bf.apellido, bf.nombre, bf.tel, bf.edad, bf.email);
            i++;
            aux = p;
            p=p->l;
            free (aux);
        }
        if (!p) u=NULL;
        
    }
    
    fclose (fp);
    system ("pause");
}
