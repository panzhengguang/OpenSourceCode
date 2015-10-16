  //1SSGJ.CPP
  //�Գ�������������
  #include  <iostream>
  #include  <cmath>
  #include  <fstream>
  using namespace std;
  class  ssgj
  {
  private: 
           int n;
		   double  **a;
  public:
	       ssgj (int nn)
		   {
			   int i;
			   n = nn;
	           a = new double*[n];   //��̬�����ڴ�ռ�
	           for (i=0; i<n; i++) a[i] = new double[n];
		   }
	       void input ();    //���ļ��������A��Ԫ��
		   void inv ();      //ִ����������
           void output ();   //���������ļ�
		   ~ssgj ()          //�ͷ��ڴ�ռ�
		   {
			   int i;
			   for (i=0; i<n; i++) { delete [] a[i]; }
			   delete [] a;
		   }
  };

  void ssgj::input ()      //���ļ��������A��Ԫ��
  {
	  int  i, j;
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
	  for (i=0; i<n; i++)                       //�������A
		  for (j=0; j<n; j++)  fin >>a[i][j];
	  fin.close ();
  }

  void ssgj::inv ()         //ִ����������
  { 
	  int i,j,k,m;
      double w,g,*b;
      b = new double[n];
      for (k=0; k<=n-1; k++)
	  { 
		  w=a[0][0];
          if (fabs(w)+1.0==1.0)
          { 
			  delete  [] b;
			  cout <<"\n�������죡"; 
			  exit(1);
		  }
          m=n-k-1;
          for (i=1; i<=n-1; i++)
          { 
			  g=a[i][0]; b[i]=g/w;
              if (i<=m) b[i]=-b[i];
              for (j=1; j<=i; j++)
                  a[i-1][j-1]=a[i][j]+g*b[j];
          }
          a[n-1][n-1]=1.0/w;
          for (i=1; i<=n-1; i++)
              a[n-1][i-1]=b[i];
      }
      for (i=0; i<=n-2; i++)
      for (j=i+1; j<=n-1; j++)
          a[i][j]=a[j][i];
      delete [] b;
  }

  void ssgj::output ()       //���������ļ�
  {
	  int  i, j;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  for (i=0; i<n; i++)
	  {
		  for (j=0; j<n; j++)
		  {
			  fout <<"    " <<a[i][j];
			  cout <<"    " <<a[i][j];
		  }
		  fout <<endl;  cout <<endl;
	  }
	  fout.close ();
  }

  void main ()      //������
  {
	  ssgj  c(4);
	  c.input ();         //���ļ��������A��Ԫ��
	  c.inv ();           //ִ����������
	  c.output ();        //���������ļ�
  }