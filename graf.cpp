#include <iostream>
#define nullptr 0

using namespace std;

struct cell{															//CELL STRUCTURE DECLARATION

	
	int numer;
	
	char val;
	
	int x_val;
	
	int y_val;
	
	cell * north;
	
	cell * west;
	
	cell * east;
	
	cell * south;
	
	cell() :east(NULL),west(NULL),north(NULL),south(NULL),val('0'),x_val(0),y_val(0),numer(0){	};
};

class Board{															//BOARD CLASS

	
	
	friend  class Tracker;
	
	public:
cell *zero_cell;	// NW cell

cell *north_east;

cell* south_west;

cell* south_east;

int MAX_X;	

int MAX_Y;	

int notfirst;
	
cell * ptr;	

cell * ptr_temp;
	
public:
	
Board(int MAX_X,int MAX_Y)	:MAX_X(0),MAX_Y(0)			//KONSTRUKTOR
{
zero_cell=new cell;

ptr=zero_cell;

notfirst=0;
int i;

for(i=1;i<MAX_X;i++)
	add_kolumn();
	
	for(i=1;i<MAX_Y;i++)
	add_row();




}


~Board()												//Destruktor
{
	int i,x;
x=MAX_Y;	
	
	for(i=0;i<=x;i++)
		{
			
			delete_row();
				
			
		}	
			
				
			
			delete zero_cell;	
				
			if(zero_cell==NULL)
			cout<<"sukces";	
				
			zero_cell=NULL;
				
			
	
	
}

void print_chessboard()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;
	
	wsk_5=wsk_4=zero_cell;

while(wsk_5)
{

while(wsk_4)	
	{
	cout<<"["<<wsk_4->x_val<<" "<<wsk_4->y_val<<"]";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}

void print()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;
	
	wsk_5=wsk_4=zero_cell;

while(wsk_5)
{

while(wsk_4)	
	{
	cout<<"["<<wsk_4->val<<"]";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}
	

void add_kolumn()	//DODAWANIE KOLUMN
{
	



	cell * wsk_4;
	cell *wsk_5;	

wsk_4=wsk_5=zero_cell;

while(wsk_4->east)
{
wsk_4=wsk_4->east;
}



north_east=wsk_4->east=new cell;
	
wsk_5=wsk_4;

wsk_4=wsk_4->east;

wsk_4->west=wsk_5;

wsk_4->x_val=wsk_4->west->x_val+1;
wsk_4->y_val=0;
	
wsk_5=wsk_5->south;

	if(notfirst==1)
	while(wsk_5)

		{
			ptr_temp=wsk_4;
			wsk_4->south=new cell;
		
			wsk_4=wsk_4->south;
		
		
			wsk_4->west=wsk_5;
			wsk_4->north=ptr_temp;
			wsk_5->east=wsk_4;
	
			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;
			
			wsk_5=wsk_5->south;
			south_east=wsk_4;
		}
		else
		south_east=north_east;

	
	if(notfirst==0){notfirst=1;	}
	
	

MAX_X++;

}



void add_row()		//DODAWANIE SZEREGOW
{
	
		


	cell * wsk_4;

	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;	


while(wsk_4->south)
{
wsk_4=wsk_4->south;
}

wsk_4->south=new cell;
	
wsk_5=wsk_4;

south_west=wsk_4=wsk_4->south;

wsk_4->north=wsk_5;

wsk_4->y_val=wsk_4->north->y_val+1;
wsk_4->x_val=0;
	
wsk_5=wsk_5->east;

	if(notfirst==1)
	while(wsk_5)
	
		{
			ptr_temp=wsk_4;
			wsk_4->east=new cell;
		
			wsk_4=wsk_4->east;
		
		
			wsk_4->north=wsk_5;
			wsk_4->west=ptr_temp;
			wsk_5->south=wsk_4;
	
			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;
			
			south_east=wsk_4;
			
			wsk_5=wsk_5->east;
		
		}

	
if(notfirst==0){notfirst=1;south_east=south_west;	}
	

MAX_Y++;

	
}



void delete_row()					//USUWANIE SZEREGOW
{
	
cell *wsk_4;	
	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;		
		
	while(wsk_4->south)
	{	
		wsk_4=wsk_4->south;
	}
	
	wsk_5=wsk_4;
	
	south_west=wsk_4->north;
	
	

	while(wsk_4)
	{
		
	if(wsk_4->north!=NULL)
		wsk_4->north->south=NULL;
		
if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}
		
		south_east=wsk_5;
		wsk_5=wsk_4->east;
		
		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
		
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;	
	}


MAX_Y--;

}

	

void delete_kolumn()						//USUWANIE KOLUMN
{
	cell *wsk_4;	
	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;	
		
	while(wsk_4->east)
{
wsk_4=wsk_4->east;
}

north_east=wsk_4;
	
	wsk_5=wsk_4;
	

	while(wsk_4)
	{
	if(wsk_4->west!=NULL)
		wsk_4->west->east=NULL;
		
		if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}
		
		south_east=wsk_5->west;
		
		wsk_5=wsk_4->south;
		
		
		
		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;	
	}

if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}

	
	MAX_X--;
	
}


		
	
	
};

class Tracker{															//TRACKER CLASS




	
int current_x_coordinate;
int current_y_coordinate;
int next_x_coordinate;	
int next_y_coordinate;	


Board *current_board;


cell * zero_cell;
	
public:
	
cell * ptr;
int *x_max;
int *y_max;	


//Konstrukctor

	Tracker(Board *b)
	{
		
	current_board=b;
	ptr=zero_cell=b->zero_cell;
	x_max=&b->MAX_X;
	y_max=&b->MAX_Y;
	current_x_coordinate=0;//zero->x_val;
	current_y_coordinate=0;//zero->y_val;
		
	}

	~Tracker()
	{
	}
	
//metody

void change_board(Board *b)
{
	current_board=b;
	ptr=zero_cell=b->zero_cell;
	x_max=&b->MAX_X;
	y_max=&b->MAX_Y;
	current_x_coordinate=0;//zero->x_val;
	current_y_coordinate=0;//zero->y_val;
	
	
}


	cell *kom(int next_x_coordinate,int next_y_coordinate)	
	{
	int k,n,i;
	
	if((0>next_x_coordinate)||(next_x_coordinate>*x_max)||(next_y_coordinate>*y_max)||(0>next_y_coordinate))
	{
		cout<<"Blad nieprawidlowe wspolrzedne tracker nie poruzy sie \n";
		return ptr;
	}
	else


	{
		
		
		k=next_x_coordinate-current_x_coordinate;
		n=next_y_coordinate-current_y_coordinate;
		
		if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
			}
		}
		
		

	current_x_coordinate=next_x_coordinate;
	current_y_coordinate=next_y_coordinate;
	
	}
	
	if(ptr==NULL)
	{
	cout<<"WARNING - out of bounds - ERROR \n";
	}
	
	return ptr;
}

	
	cell* free_track_go(int k,int n)
	{
		
		int i;
		
		
		
		
	if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0;reload_tr(); return ptr;}
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			
			if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}	
		
		current_x_coordinate=ptr->x_val;
		current_y_coordinate=ptr->y_val;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
		
		
			return ptr;
	}
	

	
	reload_tr()
	{
		ptr=zero_cell;
		current_x_coordinate=0;//zero->x_val;
		current_y_coordinate=0;//zero->y_val;
	}
	
	
};

//-------------------------------------------------------------DEKLAROWANIE ZMIENNYCH GLOBALNYCH------------------------------------------------------------------------------------------------------------------------

int i,j,x,y,input_variable,menu,AOF=0;//amount of vertices

char watever;

//-------------------------------------------------------------DEKLARACJE FUNKCJI-------------------------------------------------------------------------------------------------------------------------------------------


int get_vert(Board &BB,char vert){										//GET VERTICE COORDINATE
	Tracker T1(&BB);
	int i,c=(-1);
	
	for(i=0;i<=AOF;i++)
	if(T1.kom(i,0)->val==vert)
	return i;
		
		
			return c;
	
	
}

void swap_vert(Board &BB,int f1_st,int f2_nd){							//SWAP VERTICE VALUES AND DESCENDANT LISTS
	
	Tracker T1(&BB);
	Tracker T2(&BB);
	char temp;
	int i;
	
	for(i=0;i<=AOF ;i++)
	{
		
		temp=T1.kom(i,f1_st)->val;
		T1.kom(i,f1_st)->val=T2.kom(i,f2_nd)->val;
		T2.kom(i,f2_nd)->val=temp;
	}
	
	for(i=0;i<=AOF;i++)
	{
		
		temp=T1.kom(f1_st,i)->val;
		T1.kom(f1_st,i)->val=T2.kom(f2_nd,i)->val;
		T2.kom(f2_nd,i)->val=temp;
	}
	
	
	
	
	
}

void add_vertice(Board &BB){											//ADD VERTICE
		Tracker TT(&BB);
	int k;
	cout<<"type one character as thename of the new  vertice: ";
		cin>>watever;	
		
			k=get_vert(BB,watever);
			
			if(k!=-1){
	cout<<"a vertice named \""<<watever<<"\" already exists - choose another name \n";
					}	
else{
			
		BB.add_kolumn();
		BB.add_row();
		
		AOF++;
		
		TT.kom(AOF,0)->val=watever;
		TT.kom(0,AOF)->val=watever;
	}
		
	
}

void delete_vertice(Board &BB){											//DELETE VERTICE
	cout<<"wich vertice do you want to remove: ";
	cin>>watever;
	int k;
	
	k=get_vert(BB,watever);
	
	if(k<=0)
{
	printf("vert doesnt exist\n");
	return;
}else{
	
	if(k!=AOF)
	swap_vert(BB,k,AOF);
	
	
		BB.delete_kolumn();
		BB.delete_row();
		
		AOF--;
		
}
	
}

void add_branch(Board &BB){												//ADD BRANCH
	Tracker T1(&BB);
	int V1,V2;
	char v1,v2;
	
	cout<<"name the start vertice of the new branch: ";
	cin>>v2;
	cout<<"name the end vertice of the new branch: ";
	cin>>v1;
	
	V1=get_vert(BB,v1);
	V2=get_vert(BB,v2);
	
	if(V2<=0)
	{
	printf("start vert doesnt exist\n");
	return;
}else{
	if(V1<=0)
	{
	printf("fin vert doesnt exist\n");
	return;
}
	}
	
	
	T1.kom(V1,V2)->val='1';
	
		
}

void delete_branch(Board &BB){											//DELETE BRANCH
	Tracker T1(&BB);
	int V1,V2;
	char v1,v2;
	
	
	cout<<"name the start vertice of the branch to be deleted: ";
	cin>>v2;
	cout<<"name the end vertice of the branch to be deleted: ";
	cin>>v1;
	
	V1=get_vert(BB,v1);
	V2=get_vert(BB,v2);

	
	if(V2<=0)
	{
	printf("start vert doesnt exist\n");
	return;
}else{
	if(V1<=0){
	printf("fin vert doesnt exist\n");
	return;
}
	}
	
	
	T1.kom(V1,V2)->val='0';
	
}

void DFS(Board &BB,char vertice){							  			//DEEPH FIRST SEARCH
	
  int i,v;													//deklarujemy i
Tracker TT(&BB);
i=1;
v=get_vert(BB,vertice);

if(v==-1) return;

TT.kom(0,v)->numer=1;

   									// Zaznaczamy węzeł jako odwiedzony
 
  cout << vertice<<" - ";  									// Przetwarzamy węzeł (wypisujemy jego numer)

															// Rekurencyjnie odwiedzamy nieodwiedzonych sąsiadów

  for(i = 1; i <= AOF; i++)									//przechodzimy tablice  sasiadow v
    if((TT.kom(i,v)->val == '1') && (TT.kom(0,i)->numer!=1)) DFS(BB,TT.kom(0,i)->val);				//jesli komorka [v][i] rowna sie 1 to odwiedzamy wierzch i rekurencyjnie


	}

void BFS(Board &BB,char vertice){										//BREADTH FIRST SEARCH 
int i,j,k=0,v;
	Tracker scan(&BB);
	Tracker load(&BB);
	Tracker trace(&BB);
	BB.add_row();
	
	//v=get_vert(BB,vertice);
	
	trace.kom(0,AOF+1);
	scan.kom(0,AOF+1);
	load.kom(0,AOF+1);
	
	load.kom(0,AOF+1)->val=vertice;
	
	for(i=0;i<=AOF;i++)
	{
		
		
		v=get_vert(BB,scan.kom(i,AOF+1)->val);
		
	for(j=1;j<=AOF;j++)
		if((trace.kom(j,v)->val=='1')&&(trace.kom(0,j)->numer!=1))
			{
			load.kom(++k,AOF+1)->val=trace.kom(j,0)->val;
			trace.kom(0,j)->numer=1;
			}
			
		trace.kom(0,v)->numer=1;
		if(scan.kom(i+1,AOF+1)->val=='0') i=AOF+1;
	}

	i=1;
	while((i<=AOF)&&(scan.kom(i,AOF+1)->val!='0'))
	{
		cout<<scan.kom(i++,AOF+1)->val<<" ";
	}
	
BB.delete_row();
cout<<"\n";
}

void reset_visited(Board &BB){											//RESET VISITED LIST
int i;	
Tracker TT(&BB);
Tracker T(&BB);
	
	for(i = 0; i <= AOF; i++)
{
	TT.kom(0,i)->numer=0;
	T.kom(0,i)->numer=0;

}

}

void sort_AB(Board &BB){												//VERTICE SORTING (TBD)
}

	
//-------------------------------------------------------------MAIN----------------------------------------------------------------------------------------------------------------------------------------------------
	

int main(){
	

Board b_1(0,0);
	
	
	
Tracker t_1(&b_1);
	
t_1.kom(0,0)->val='>';

//---------------------------------TUTAJ JEST MENU-------------------------------------------------------------

int holder;

holder=1;
while(holder==1)
{
cout<<"\n Menu : \n";
cout<<" 1.print graph matrix\n";
cout<<" 2.add_vertice \n";
cout<<" 3.add_branch \n";
cout<<" 4.delete_vertice \n";
cout<<" 5.delete_branch \n";
cout<<" 6.BFS\n";
cout<<" 7.DFS\n";

cout<<" 20.exit \n";

cin>>menu;

switch(menu)
{
		case 1:{				//WYSWIETL
			
		b_1.print();
		break;
		}
	
	
		case 2 :		
		{	
			
		add_vertice(b_1);
			
			
		
			
			break;
			
		}
		
		case 3:			
		{		
			
		add_branch(b_1);
			
			
			break;
		}
		
		
		case 4:			//USUWANIE WIERZCHOŁKOW
		{		
			
		delete_vertice(b_1);
			
			break;
		}
		
		
		case 5:			//USUWANIE GAŁĘZI
		{	
			
		delete_branch(b_1);

			break;
		}
		
		case 6:{				//BFS
			cout<<"name the starting vertice: ";
			cin>>watever;
			
			BFS(b_1,watever);
			
			reset_visited(b_1);				
		break;
		
		break;
		}
		
		case 7:{				//DFS
			cout<<"name the starting vertice: ";
			cin>>watever;
			
			DFS(b_1,watever);
			
			reset_visited(b_1);				
		break;
		}
	
		
		
		case 11:{			//////TEST SPOJNOSCI
			
		cin>>x;
		cin>>y;	
		cin>>watever;
			
	t_1.kom(x,y)->val=watever;
		
			break;
		}
		
		
		case 12:			//WYSWIETL WPOŁRZEDNE
		{		
			
			b_1.print_chessboard();
			break;
		}
		
		
		
		
		case 13:
			{
				
				
				
				break;
			}
		
	
		case 14:			// TEST SPOJNOSCI SIATKI
		{	 			
			
			cout<<b_1.zero_cell->x_val<<b_1.zero_cell->y_val<<"\n";
			cout<<b_1.north_east->x_val<<b_1.north_east->y_val<<"\n";
			cout<<b_1.south_east->x_val<<b_1.south_east->y_val<<"\n";
			cout<<b_1.south_west->x_val<<b_1.south_west->y_val<<"\n";
		
		
			break;
		}
	
	
	case 20:			//WYJSCIE
		{
			
		
			
		holder=0;
		break;
		}
	
	
	
	
	
	
}//koniec swticha
}









	system("PAUSE");
	
	return 0;
}

