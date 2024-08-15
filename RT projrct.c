#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 5000
struct marks // for every subject
{
    float bangla_1;
    float bangla_2;
    float eng_1;
    float eng_2;
    float phy_1;
    float phy_2;
    float math_1;
    float math_2;
    float chem_1;
    float chem_2;
    float bio_1;
    float bio_2;
    float ict;
};

struct sub_wise_grade  // for individual subject grade
{
    float bangla_gpa;
    float eng_gpa;
    float phy_gpa;
    float math_gpa;
    float chem_gpa;
    float bio_gpa;
    float ict_gpa;
};

struct Student // general info of a student
{
    char name[50];
    char roll[10];
    char registration[10];
    float gpa;
    struct marks mark;
    struct sub_wise_grade grade;
};
float mark_to_grade(float, float);
float mark_to_grade_ict(float ); // function prototypes
float gpa_counter(struct Student [],int n);
void enter_info(struct Student [],int n);
void display_info(struct Student [],int n);
void search_st(struct Student [],int,char[]);
void store_all_info(struct Student st[], int n);

int main()
{
    struct Student st[N]; // array of structures

    int n=0; // will work as the counter of students data stored
    char search[50];
    char input;
    while(input != 'q')
    {
        printf("\n\n");
        printf("\t\t##############################\n");
        printf("\t\t||      HSC GPA             ||\n");
        printf("\t\t||      CALCULATOR          ||\n");
        printf("\t\t||                          ||\n");
        printf("\t\t##############################\n");

        printf("\n\n\t\tEnter 'a' to add information of a student\n");
        printf("\t\tEnter 'd' to display & store student info of all the students inside the database\n");
        printf("\t\tEnter 's' to search for a student\n");
        printf("\t\tEnter 'q' to  quit the system\n");
        printf("\n\t\tEnter  your choice:");
        fflush(stdin);
        scanf("%c",&input);
        switch(input)
        {
        case 'a':
            enter_info(st,n);
            n++;
            break;
        case 'd':
            display_info(st,n);
            store_all_info(st, n);
            break;
        case 'q':
            continue;
        case 's':
            fflush(stdin);
            printf("Enter roll:");
            gets(search);
            search_st(st,n,search);
            break;
        default:
            printf("!!! Invalid Input !!!");
        }

    }
    return 0 ;
}

void enter_info(struct Student st[],int n) // only for taking entry and saving gpa
{
    fflush(stdin);
    printf("Enter your name: ");
    gets(st[n].name);

    fflush(stdin);

    printf("\nEnter your roll: ");
    gets(st[n].roll);
    fflush(stdin);

    printf("\nEnter your registration: ");
    gets(st[n].registration);


    printf("\nMarks in BANGLA 1st paper: ");
    scanf("%f",&st[n].mark.bangla_1);

    fflush(stdin);
    printf("\nMarks in BANGLA 2nd paper: ");
    scanf("%f",&st[n].mark.bangla_2);

    printf("\nMarks in English 1st paper: ");
    scanf("%f",&st[n].mark.eng_1);

    printf("\nMarks in English 2nd paper: ");
    scanf("%f",&st[n].mark.eng_2);

    printf("\nMarks in physics 1st paper: ");
    scanf("%f",&st[n].mark.phy_1);

    printf("\nMarks in physics 2nd paper: ");
    scanf("%f",&st[n].mark.phy_2);

    printf("\nMarks in Math 1st paper: ");
    scanf("%f",&st[n].mark.math_1);

    printf("\nMarks in Math 2nd paper: ");
    scanf("%f",&st[n].mark.math_2);

    printf("\nMarks in Biology 1st paper: ");
    scanf("%f",&st[n].mark.bio_1);

    printf("\nMarks in Biology 2nd paper: ");
    scanf("%f",&st[n].mark.bio_2);

    printf("\nMarks in chemistry 1st paper: ");
    scanf("%f",&st[n].mark.chem_1);

    printf("\nMarks in chemistry 2nd paper: ");
    scanf("%f",&st[n].mark.chem_2);

    printf("\nMarks in ict: ");
    scanf("%f",&st[n].mark.ict);

    st[n].gpa = gpa_counter(st,n); // call for gpa

    printf("\nGPA:%.2f\n",st[n].gpa);

    printf("\t\t****DATA ENTRY SUCCESSFULL****\n\n");
}

float mark_to_grade(float paper_1, float paper_2) // others sub er jonno eta use korbo
{
    float g, sum=0;
    if(paper_1>=33 && paper_2>=33)
    {
        sum=paper_1 + paper_2;
        if(sum >= 160 && sum <= 200)
            g=5.00;
        else if(sum>=140 && sum<=159)
            g=4.00;
        else if(sum>=120 && sum<=139)
            g=3.50;
        else if(sum>=100 && sum<=119)
            g=3.00;
        else if(sum>=80 && sum<=99)
            g=2.00;
        else if(sum>=66 && sum<=89)
            g=1.00;

    }
    else
        g=0.00;
    return g;
}

float mark_to_grade_ict(float mark) // ict er jonno eta use korbo
{
    float g;

    if(mark>=33)
    {
        if(mark >= 80 && mark <= 100)
            g=5.00;
        else if(mark>=70 && mark<=79)
            g=4.00;
        else if(mark>=60 && mark<=69)
            g=3.50;
        else if(mark>=50 && mark<=59)
            g=3.00;
        else if(mark>=40 && mark<=49)
            g=2.00;
        else if(mark>=33 && mark<=39)
            g=1.00;
    }
    else
        g=0.00;
    return g;
}

float gpa_counter(struct Student st[],int n)
{
    /*
    Using two different functions for counting gpa of them according to papers. We will be adding them
    after each count
    */
    float sum=0;


    st[n].grade.bangla_gpa= mark_to_grade(st[n].mark.bangla_1, st[n].mark.bangla_2);
    if(st[n].grade.bangla_gpa<1)
        return 0.00;
    else
        sum += st[n].grade.bangla_gpa;

    st[n].grade.eng_gpa = mark_to_grade(st[n].mark.eng_1, st[n].mark.eng_2);
    if(st[n].grade.eng_gpa<1)
        return 0.00;
    else
        sum += st[n].grade.eng_gpa ;

    st[n].grade.phy_gpa = mark_to_grade(st[n].mark.phy_1, st[n].mark.phy_2);
    if(st[n].grade.phy_gpa<1)
        return 0;
    else
        sum += st[n].grade.phy_gpa ;

    st[n].grade.math_gpa = mark_to_grade(st[n].mark.math_1, st[n].mark.math_2);
    if(st[n].grade.math_gpa<1)
        return 0.00;
    else
        sum +=st[n].grade.math_gpa ;

    st[n].grade.chem_gpa = mark_to_grade(st[n].mark.chem_1, st[n].mark.chem_2);
    if(st[n].grade.chem_gpa<1)
        return 0.00;
    else
        sum += st[n].grade.chem_gpa ;

    st[n].grade.ict_gpa = mark_to_grade_ict(st[n].mark.ict);
    if(st[n].grade.ict_gpa<1)
        return 0.00;
    else
        sum += st[n].grade.ict_gpa ;

    st[n].grade.bio_gpa = mark_to_grade(st[n].mark.bio_1, st[n].mark.bio_2);

    if(st[n].grade.bio_gpa>=2)
    {
        sum += st[n].grade.bio_gpa - 2;
    }


    if(sum>30)
        sum=30;

    return sum/6.0;

}
void display_info(struct Student st[],int n)
{
    printf("\nDATA OF ALL THE STUDENTS\n");
    printf("%-50s%-10s\n","NAME","HSC GPA");
    for(int i=0 ; i<n ; i++)
    {
        printf("%-50s",st[i].name);
        printf("%-10.2f\n",st[i].gpa);
    }
}

void search_st(struct Student st[],int n,char search[])
{
    int flag=0;
    for(int i = 0 ; i< n ; i++ )
    {
        if( strcmp( search,st[i].roll)== 0 )
        {
            flag=1;
            printf("\n");
            printf("Name         :  %s\n",st[i].name);
            printf("Roll         : %s\n",st[i].roll);
            printf("Registration : %s\n",st[i].registration);

            printf("|------------------------|\n");
            printf("|      MARKS             |\n");
            printf("|------------------------|\n");



            printf("BANGLA 1ST PAPER    :%.2f\n",st[i].mark.bangla_1);
            printf("BANGLA 2nd PAPER    :%.2f\n",st[i].mark.bangla_2);
            printf("\nBANGLA GRADE        :%.2f\n\n",st[i].grade.bangla_gpa);
            //gpa in bangla
            printf("ENGLISH 1ST PAPER   :%.2f\n",st[i].mark.eng_1);
            printf("ENGLISH 2ND PAPER   :%.2f\n",st[i].mark.eng_2);
            printf("\nENGLISH GRADE       :%.2f\n\n",st[i].grade.eng_gpa);
            //gpa in english
            printf("PHYSICS 1ST PAPER   :%.2f\n",st[i].mark.phy_1);
            printf("PHYSICS 2ND PAPER   :%.2f\n",st[i].mark.phy_2);
            printf("\nPHYSICS GRADE       :%.2f\n\n",st[i].grade.phy_gpa);
            // gpa in physics
            printf("MATH 1ST PAPER      :%.2f\n",st[i].mark.math_1);
            printf("MATH 2ND PAPER      :%.2f\n",st[i].mark.math_2);
            printf("\nMATH GRADE          :%.2f\n\n",st[i].grade.math_gpa);
            //gpa in math
            printf("CHEMISTRY 1ST PAPER :%.2f\n",st[i].mark.chem_1);
            printf("CHEMISTRY 2NDPAPER  :%.2f\n",st[i].mark.chem_2);
            printf("\nCHEMISTRY GRADE     :%.2f\n\n",st[i].grade.chem_gpa);
            // gpa in chemistry
            printf("BIOLOGY 1ST PAPER   :%.2f\n",st[i].mark.bio_1);
            printf("BIOLOGY 2ND PAPER   :%.2f\n",st[i].mark.bio_2);
            printf("\nBIOLOGY GRADE       :%.2f\n\n",st[i].grade.bio_gpa);
            //gpa in biology
            printf("ICT                 :%.2f\n",st[i].mark.ict);
            printf("\nICT GRADE          :%.2f\n\n",st[i].grade.ict_gpa);
            // gpa in ict
            printf("\n\nFINAL  GPA:%.2f\n\n",st[i].gpa);

        }
    }
    if(flag==0)
        printf("!!! NOT found !!!!\n");


}

void store_all_info(struct Student st[], int n)
{
    FILE *all;
    all=fopen("hsc all info.txt", "a");

    if(all==NULL)
        printf("File doesn't exist!!");
    else
    {
        fprintf(all, "DATA OF ALL THE STUDENTS\n\n");
        fprintf(all, "%-30s%-10s%-15s%-10s%10s%10s%10s%10s%10s%12s%12s\n","NAME", "ROLL","REGISTRATION",
               "HSC GPA", "B_GPA", "E_GPA","P_GPA", "M_GPA", "C_GPA", "BIO_GPA", "ICT_GPA");

       for(int i=0; i<n; i++)
       {
            fprintf(all, "%-30s",st[i].name);
            fprintf(all, "%-10s",st[i].roll);
            fprintf(all, "%-15s",st[i].registration);
            fprintf(all, "%-15.2f",st[i].gpa);
            fprintf(all, "%-10.2f",st[i].grade.bangla_gpa);
            fprintf(all, "%-10.2f",st[i].grade.eng_gpa);
            fprintf(all, "%-10.2f",st[i].grade.phy_gpa);
            fprintf(all, "%-10.2f",st[i].grade.math_gpa);
            fprintf(all, "%-10.2f",st[i].grade.chem_gpa);
            fprintf(all, "%-12.2f",st[i].grade.bio_gpa);
            fprintf(all, "%-12.2f\n",st[i].grade.ict_gpa);
       }

    }
}

