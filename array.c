int fun(int *);

int main()
{
int a[10];

fun(&a); /* &a-> address of a[10]; */
fun(a);  /* a -> address of a */

}


int fun (int *a) {

return 0;
}
