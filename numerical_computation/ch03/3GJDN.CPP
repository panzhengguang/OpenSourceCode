  //3GJDN.CPP
  //ȫѡ��ԪGauss-Jordan��ȥ�����ʵϵ��������
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  gjdn
  {
  private: 
           int n, m;
		   double  **a, **b;
  public:
	       gjdn (int nn, int mm)
		   {
			   int i;
			   n = nn; m = mm;
	           a = new double*[n];   //��̬�����ڴ�ռ�
	           for (i=0; i<n; i++) a[i] = new double[n];
	           b = new double*[n];
	           for (i=0; i<n; i++) b[i] = new double[m];
		   }
	       void input ();        //���ļ�����ϵ������A�Լ�m�鳣������B
		   void gauss_jordan ();      //ִ��Gauss-Jordan��ȥ��
           void output ();       //���������ļ�����ʾ
		   ~gjdn ()
		   {
			   int i;
			   for (i=0; i<m; i++) { delete [] a[i]; }
			   delete [] a;
			   delete [] b;
		   }
  };

  void gjdn::input ()      //���ļ�����ϵ������A�Լ�m�鳣������B
  {
	  int  i, j;
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
	  for (i=0; i<n; i++)                       //����ϵ������A
		  for (j=0; j<n; j++)  fin >>a[i][j];
	  for (i=0; i<m; i++)                       //����m�鳣������B
	  for (j=0; j<n; j++)  fin >>b[j][i];
	  fin.close ();
  }

  void gjdn::gauss_jordan ()          //ִ��Gauss-Jordan��ȥ��
  { 
	  int *js,l,k,i,j,is;
      double d,t;
      js = new int[n];
      l=1;
      for (k=0;k<=n-1;k++)
      { 
		  d=0.0;
          for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
          { 
			  t=fabs(a[i][j]);
              if (t>d) { d=t; js[k]=j; is=i;}
          }
          if (d+1.0==1.0) l=0;
          else
          { 
			  if (js[k]!=k)
                for (i=0;i<=n-1;i++)
                { 
                    t=a[i][k]; 
					a[i][k]=a[i][js[k]]; 
					a[i][js[k]]=t;
                }
              if (is!=k)
              { 
				  for (j=k;j<=n-1;j++)
                  { 
                      t=a[k][j]; 
					  a[k][j]=a[is][j]; 
					  a[is][j]=t;
                  }
                  for (j=0;j<=m-1;j++)
                  { 
                      t=b[k][j]; 
					  b[k][j]=b[is][j]; 
					  b[is][j]=t;
                  }
              }
          }
          if (l==0)
          { 
			  delete []js;
			  cout <<"\nϵ���������죡�޽�. " <<endl;
              return;
          }
          d=a[k][k];
          for (j=k+1;j<=n-1;j++)
             a[k][j]=a[k][j]/d;
          for (j=0;j<=m-1;j++)
             b[k][j]=b[k][j]/d;
          for (j=k+1;j<=n-1;j++)
          for (i=0;i<=n-1;i++)
          { 
              if (i!=k)
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
          }
          for (j=0;j<=m-1;j++)
          for (i=0;i<=n-1;i++)
          { 
              if (i!=k)
              b[i][j]=b[i][j]-a[i][k]*b[k][j];
          }
      }
      for (k=n-1;k>=0;k--)
        if (js[k]!=k)
          for (j=0;j<=m-1;j++)
          { 
              t=b[k][j]; b[k][j]=b[js[k]][j]; b[js[k]][j]=t;
          }
      delete [] js;
  }

  void gjdn::output ()       //���������ļ�����ʾ
  {
	  int  i, j;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  fout <<endl;  cout <<endl;
	  for (i=0; i<m; i++)
	  {
		  for (j=0; j<n; j++)
		  {

		      fout <<b[j][i] <<"   ";
		      cout <<b[j][i] <<"   ";
		  }
		  fout <<endl;  cout <<endl;
	  }
	  fout <<endl;  cout <<endl;
	  fout.close ();
  }

  void main ()      //������
  {
	  gjdn  c(4, 2);
	  c.input ();         //���ļ�����ϵ������A�Լ�m�鳣������B
	  c.gauss_jordan ();  //ִ��Gauss-Jordan��ȥ��
	  c.output ();        //���������ļ�����ʾ
  }
