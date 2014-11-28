#ifndef TYPE_H
#define TYPE_H


#define INSTANCE_PORTREF 1
#define TOP_PORTREF	     0			

#define MAX_PRIM_ID_LENGTH 	 	20
//lib_name
//cell_id(a cell's name: FDR,LUT4,DSP,user_define_cell's id  ....)
//view_id(a view's name :)
//port_id,


#define MAX_USER_ID_LENGTH   	50
//instance_id,net_id,instanceref_id(每一个instanceref对应着一个instance_id)
typedef struct edif_t  			   top_EDIF;

typedef struct ref_library_t  	   REF_LIBRARY;
typedef struct prim_cell_t   	   PRIM_CELL;
typedef struct port_t  			   PORT;

typedef struct cell_t 			   CELL;
typedef struct view_t 			   VIEW;

typedef struct instance_t    	   INSTANCE;
typedef struct view_cell_lib_ref_t VIEW_CELL_LIB_REF;

typedef struct net_t			   NET;
typedef struct portref_t		   PORTREF;

typedef struct property_t          PROPERTY;

struct edif_t{
	char        edif_name[20];
	int         reflib_cnt;
	REF_LIBRARY *reflib_list;
	int         work_cells_cnt;
	CELL        *work_cells;
	char		design_name[20];
};
//-------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------

struct ref_library_t{
	//需要传递给上一级的信息	
	int list_cnt;
	//当前ref_library的信息
	char lib_name[MAX_PRIM_ID_LENGTH]; //ie: UNILIB VIRTEX VIRTEXR...		
		//从下一级传上来的信息
	int cell_count;	  //这个参考库中包含的CELL的个数,实际上就是PRIM_list的list_cnt
	PRIM_CELL *prim_in_lib;
};	

struct prim_cell_t{
	//需要传递给上一级的信息	
	int list_cnt; 	 //记录prim_cell这个list的个数，只需要对list中的element1来记就可以了
	
	//当前prim_cell的信息
	char cell[MAX_PRIM_ID_LENGTH];   
	int  celltype;
	int  view;	
	int  viewtype;
		//从下一级传上来的信息
	int port_number; //interface中port的个数,实际上就是port_list的list_cnt
	PORT *interface;
};

struct port_t{
	//需要传递给上一级的信息
	int  list_cnt;         //记录port_list当中含有的port的个数，只需要对一个list的p1当中赋予正确的值就可以了
	
	//本port的信息
	char port_name[MAX_PRIM_ID_LENGTH];	   //every port has a name 	
	int  port_member_count;//a array port has more than one member,such as input[3:0] has four member 
	int  d;                //direction was a token , and impliey by an int type in default 
};


//-------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------


struct cell_t{
	int  list_cnt;
	char cell[MAX_PRIM_ID_LENGTH];
	int  celltype;
	VIEW *view;
};
struct view_t{
	int  view;
	int  viewtype;
	
	int  port_number;
	PORT *interface;
	//以下两部分共同组成了contents 
	int  	 instance_number;
	INSTANCE *instance_list;
	int   	 net_number;
	NET      *net_list;
	//property
	int 	 property_number;
	PROPERTY *property_list;
};

//------------------------------------------------------------------------------------------
//instance的数据类型定义
//------------------------------------------------------------------------------------------
struct instance_t{

	//需要传递给上一级的数据
	int list_cnt;

	//当前本级的信息	
	int  instance_type;  //PRIM or just a cell in lib work
	char name[MAX_USER_ID_LENGTH];
	//根据前面的语意值来的信息
	VIEW_CELL_LIB_REF 	   *view_cell_lib_id;
	PROPERTY 	   		   *p_instance_property;
};

struct view_cell_lib_ref_t{
	char viewref_id	[MAX_PRIM_ID_LENGTH];
    char cellref_id	[MAX_USER_ID_LENGTH];
	char libref_id 	[MAX_PRIM_ID_LENGTH];
};


struct   property_t{
	int  list_cnt;
	char property_id	[MAX_PRIM_ID_LENGTH]; //INIT or sth.......
	char property_type	[MAX_PRIM_ID_LENGTH]; //integer or string 
	union {
	char property_string_value	[MAX_PRIM_ID_LENGTH];
	int  property_num_value;
	}property_value;
};

//------------------------------------------------------------------------------------------
//net的数据类型定义
//------------------------------------------------------------------------------------------
struct net_t{

	int list_cnt;
	char net_name[MAX_USER_ID_LENGTH];
	int  portref_number;
	PORTREF *portref_list;
};
struct portref_t{

	int  list_cnt;
	int  portref_type; //this cell's bus,port OR the instance's port
	char portref_id		[MAX_PRIM_ID_LENGTH]; //端口的ID
	int  bit_location;	//当一个NET连接到多位PORT的其中一位时,要根据名字寻找端口,但是必须要有记录bit位的信息
	char instanceref_id	[MAX_USER_ID_LENGTH];//instance的id,如果是当前cell的顶层端口,就没有ID
};
#endif 









