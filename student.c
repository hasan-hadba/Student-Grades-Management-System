#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 1. استخدام الـ Structs لتنظيم سجلات الطلاب
typedef struct
{
    string name;
    int id;
    float grades[3]; // مصفوفة درجات لـ 3 مواد
    float gpa;
}
student;

// تعريف الدوال (Prototypes)
float calculate_average(float grades[], int n);

int main(void)
{
    printf("--- Student Grades Management System ---\n");

    // 2. استخدام الـ Arrays لتخزين مجموعة طلاب
    int count = get_int("How many students to record? ");
    student class_list[count];

    // إدخال البيانات
    for (int i = 0; i < count; i++)
    {
        printf("\nStudent #%d Details:\n", i + 1);
        class_list[i].name = get_string("Full Name: ");
        class_list[i].id = get_int("Student ID: ");

        for (int j = 0; j < 3; j++)
        {
            class_list[i].grades[j] = get_float("Grade for Subject %d: ", j + 1);
        }

        // 3. تطبيق خوارزمية حساب المعدل
        class_list[i].gpa = calculate_average(class_list[i].grades, 3);
    }

    // 4. فلترة الأداء (Filtering Performance)
    printf("\n--- Final Academic Records ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %-10s | GPA: %.2f | Status: ",
                class_list[i].id, class_list[i].name, class_list[i].gpa);

        if (class_list[i].gpa >= 90)
        {
            printf("[Honor Roll / Excellent]\n");
        }
        else if (class_list[i].gpa >= 60)
        {
            printf("[Passing]\n");
        }
        else
        {
            printf("[Academic Warning]\n");
        }
    }
}

// خوارزمية حساب المعدل البسيطة (Algorithm)
float calculate_average(float grades[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += grades[i];
    }
    return sum / n;
}
