  //1TRMUL.CPP
  //ʵ�������
  #include  <iostream>
  #include  <fstream>
  using namespace std;
  class  trmul
  {
  private: 
           int m, n, k;
		   double  **a, **b, **c;
  public:
	       trmul (int mm, int nn, int kk)
		   {
			   int i;
			   m = mm; n = nn; k = kk;
	           a = new double*[m];      //��̬�����ڴ�ռ�
	           for (i=0; i<m; i++) a[i] = new double[n];
	           b = new double*[n];
	           for (i=0; i<n; i++) b[i] = new double[k];
	           c = new double*[m];
	           for (i=0; i<m; i++) c[i] = new double[k];
		   }
	       void input ();    //���ļ��������A��B
		   void mul ();      //ִ��C=AB
           void output ();   //����Cд���ļ�
		   ~trmul ()
		   {
			   int i;
			   for (i=0; i<m; i++) { delete [] a[i]; }
			   delete [] a;
			   for (i=0; i<n; i++) { delete [] b[i]; }
			   delete [] b;
			   for (i=0; i<m; i++) { delete [] c[i]; }
			   delete [] c;
		   }
  };

  void trmul::input ()      //���ļ��������A��B
  {
	  int  i, j;
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
	  for (i=0; i<m; i++)                       //�������A
		  for (j=0; j<n; j++)  fin >>a[i][j];
	  for (i=0; i<n; i++)                       //�������B
		  for (j=0; j<k; j++)  fin >>b[i][j];
	  fin.close ();
  }

  void trmul::mul ()         //ִ��C=AB
  { 
	  int i, j, t;
      for (i=0; i<m; i++)
      for (j=0; j<k; j++)
      { 
		  c[i][j] = 0.0;
		  for (t=0; t<n; t++)
			  c[i][j] = c[i][j] + a[i][t]*b[t][j];
      }
  }

  void trmul::output ()       //����Cд���ļ�
  {
	  int  i, j;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  for (i=0; i<m; i++)
	  {
		  for (j=0; j<k; j++)
		  {
			  fout <<"    " <<c[i][j];
			  cout <<"    " <<c[i][j];
		  }
		  fout <<endl; cout <<endl;
	  }
	  fout.close ();
  }

  void main ()      //������
  {
	  trmul  c(4, 5, 3);
	  c.input ();     //���ļ��������A��B
	  c.mul ();       //ִ��C=AB
	  c.output ();    //�������C���ļ�
  }
