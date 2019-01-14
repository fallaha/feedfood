#include "information.h"
#include "file.h"
#include "string.h"
#include <stdint.h>
#include "food.h"

struct information {
    char password [16];
    char nostudent [11];
    char name [20];
    char family [20];
    uint32_t money ;
    uint8_t food [FD_MAX_DAY][FD_MAX_MEAL]; /* information.food[d][m] */
};
static struct information information;

uint32_t inf_get_money (){
    return information.money;
}

void inf_set_money (uint32_t m){
    information.money = m;
    file_save(&information);;
}

void inf_add_money (uint32_t m){
    information.money += m;
    file_save(&information);;
}

void inf_dec_money (uint32_t m){
    information.money -= m;
    file_save(&information);;
}

void inf_set_password (char pass[]){
    strcopy(pass,&information.password,sizeof(information.password));
    file_save(&information);;
}
void inf_get_password (char *pass){
    strcopy(&information.password,pass,sizeof(information.password));
}

void inf_get_nostudent (char *nos){
    strcopy(&information.nostudent,nos,sizeof(information.nostudent));
}

void inf_set_name(char name[]){
    strcopy(name,&information.name,sizeof(information.name));
    file_save(&information);;
}
void inf_get_name (char *name){
    strcopy(&information.name,name,sizeof(information.name));
}

void inf_set_family (char family[]){
    strcopy(family,&information.family,sizeof(information.family));
    file_save(&information);;
}
void inf_get_family (char *family){
    strcopy(&information.family,family,sizeof(information.family));
}

uint8_t inf_get_nofood (int d,int v){
    return information.food[d][v];
}

uint8_t inf_set_nofood (int d,int v,int nf){
    return information.food[d][v] = nf;
    file_save(&information);
}

void inf_makeuser (char nostudent [],char password []){
    struct information inf;
    /* set 0 to struct to avoid of any wrong */
    str_memset(&inf,0,sizeof(inf));

    strcopy(password,&inf.password,sizeof(inf.password));    /* Set password */
    strcopy(nostudent,&inf.nostudent,sizeof(inf.nostudent)); /* Set Student Number */

    file_create (nostudent);
    file_save (&inf);

}

void inf_checkpass (char pass []){
    return str_cmp(information.password,pass);

}
void inf_initialize (){
    file_read (&information);
}