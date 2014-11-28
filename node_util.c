#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include "type.h"

#define print_node 0 
//#define TRACE

#ifdef  TRACE
#define print_node 1
#endif


#define NEW_LIST(LIST_TYPE,POINTER); \
						LIST_TYPE *POINTER;\
						POINTER=(LIST_TYPE *)malloc(sizeof(LIST_TYPE));\
						if(POINTER==NULL){\
							printf("error:malloc in newList();\n");\
							exit(1);\
						}\
					
#define NEW_ENTRY(LIST_TYPE,EXISTED,ITEM_AFTER_ADD,POINTER);  \
					{ \
						POINTER=(LIST_TYPE*)realloc(EXISTED,ITEM_AFTER_ADD*sizeof(LIST_TYPE));\
						if(POINTER==NULL){\
							printf("error: realloc() in newList_Entry();\n");\
							exit(1);\
						}\
					}


#define SAFE_STRCPY(DST,SOUR,MAX_DST_LENG);		\
					{ \
						if(strlen(SOUR)>MAX_DST_LENG) {\
							printf("Error:source str length >MAX_ID_LENGTH");\
							printf("The source string length is %d",strlen(SOUR));\
							exit(1);\
						}\
						else strcpy(DST,SOUR);\
					}
//-----------------------------------------------------------------------------------------------------------

top_EDIF *createEdif(char *edif_name,REF_LIBRARY *reflib_list,CELL *work_cells,char *design_name){
	top_EDIF *p1;
	p1=(top_EDIF *)malloc(sizeof(top_EDIF));
	
	SAFE_STRCPY(p1->edif_name,edif_name,20);
	p1->reflib_cnt		=reflib_list->list_cnt;
	p1->reflib_list		=reflib_list;
	p1->work_cells_cnt	=work_cells->list_cnt;
	p1->work_cells		=work_cells;
	SAFE_STRCPY(p1->design_name,design_name,20);
	return p1;
}
//-----------------------------------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------------------------------
PORT *createPort(int number,char *name,int dir){
	NEW_LIST(PORT,p1);
	SAFE_STRCPY(p1->port_name,name,MAX_PRIM_ID_LENGTH);
	p1->port_member_count  =number;
	p1->d			 	   =dir;
	if(print_node){
		printf("Create port:%s,dir(%d),width(%d)\n",p1->port_name,p1->d,p1->port_member_count);	
	}	
	return p1;
}

PORT *newPort_List(PORT *first_port){
	NEW_LIST(PORT,p1);
	p1->list_cnt 			=1;
	/*p1->port_name=(char *)malloc(sizeof(char)*(strlen(first_port->port_name)));//为p1的字符串指针成员赋值之前必须,为之分配内存
	if(p1->port_name==NULL) 
		printf("malloc error for p1->port_name in newList()\n");	
	p1->port_name  			=strcpy(p1->port_name,first_port->port_name);
	*/
	//将此空间中的第一个元素,填充为first_port的内容;
	strcpy(p1->port_name,first_port->port_name);
	p1->port_member_count	=first_port->port_member_count;
	p1->d  			        =first_port->d;
	if(print_node){
		printf("New port list;\n");	
	}
	//free(first_port->port_name);
	free(first_port);
	return p1;
}

PORT *newPort_List_Entry(PORT *existed_list,PORT *new_entry,int port_number_now){

	PORT *p1;
	NEW_ENTRY(PORT,existed_list,port_number_now,p1);
	/*p1=(PORT *)realloc(existed_list,port_number_now*sizeof(PORT));
	if(p1==NULL) 
		{printf("error: realloc() in newList_Entry();\n");exit(1);}
	*/
	p1->list_cnt=port_number_now;//用第一个元素的一个成员来记录这个list所含的元素的个数
	PORT *p2; 
	p2=p1+port_number_now-1;
	strcpy(p1->port_name,new_entry->port_name);
	//p2->port_name			=(char *)malloc(sizeof(char)*strlen((new_entry->port_name)));	
	//p2->port_name  			=strcpy(p2->port_name,new_entry->port_name);
	p2->port_member_count	=new_entry->port_member_count;
	p2->d		  			=new_entry->d;
	if(print_node){
		printf("Add new entry.list_cnt is :%d\n",port_number_now);
	}
	//free(new_entry->port_name);
	free(new_entry);
	return p1;
}


//-----------------------------------------------------------------------------------------------------------
// 参考库中的原语识别,构建列表的函数
//-----------------------------------------------------------------------------------------------------------
PRIM_CELL *createPrim(char *cell,int cell_type,int view,int view_type,PORT *interface){
	NEW_LIST(PRIM_CELL,p1);
	//p1->ID_MALLOC(cell,cell);
	//p1->cell       =strcpy(p1->cell,cell);
	SAFE_STRCPY(p1->cell,cell,MAX_PRIM_ID_LENGTH);
	p1->celltype   =cell_type;
	p1->view       =view;
	p1->viewtype   =view_type;
	p1->port_number=interface->list_cnt;
	p1->interface  =interface;
	return p1;
}

PRIM_CELL *newPrim_List(PRIM_CELL *first_prim_cell){
	NEW_LIST(PRIM_CELL,p1);
	//	p1->ID_MALLOC(cell,first_prim_cell->cell);
	//	p1->cell 	 	=strcpy(p1->cell,first_prim_cell->cell);
	p1->list_cnt=1;
	strcpy(p1->cell,first_prim_cell->cell);
	p1->celltype 	=first_prim_cell->celltype;
	p1->view     	=first_prim_cell->view;
	p1->viewtype 	=first_prim_cell->viewtype;
	p1->port_number =first_prim_cell->list_cnt;
	p1->interface	=first_prim_cell->interface;
	//由于在前面创造的interface存放在内存空间中的连续块中，而且没有被释放，所以只需要记住它的起始地址就好了。
	//并且这些内存空间是需要后面分析使用的，所以在main()运行期间一直不释放
	//free(first_prim_cell->cell);
	free(first_prim_cell);
	return p1;
}

PRIM_CELL *newPrim_List_Entry(PRIM_CELL *existed_list,PRIM_CELL *new_entry,int list_cnt){
	
	PRIM_CELL *p1;
	NEW_ENTRY(PRIM_CELL,existed_list,list_cnt,p1);
	
	p1->list_cnt=list_cnt;
	//对最后一个element赋值
	PRIM_CELL *p2;
	p2=p1+list_cnt-1;
	//p2->ID_MALLOC(cell,new_entry->cell);
	//p2->cell 		=strcpy(p2->cell,new_entry->cell);
	strcpy(p1->cell,new_entry->cell);
	p2->view 		=new_entry->view;
	p2->viewtype 	=new_entry->viewtype;	
	p2->port_number =new_entry->list_cnt;
	p2->interface   =new_entry->interface;
	
	//释放无用内存
	//free(new_entry->cell);
	free(new_entry);
	return p1;
}


//-----------------------------------------------------------------------------------------------------------
//构建参考库,参考库列表的函数
//-----------------------------------------------------------------------------------------------------------
REF_LIBRARY *createRef_Lib(char *lib_name,PRIM_CELL *prim_list){
	NEW_LIST(REF_LIBRARY,p1);
	SAFE_STRCPY(p1->lib_name,lib_name,MAX_PRIM_ID_LENGTH);
	p1->cell_count		=prim_list->list_cnt;
	p1->prim_in_lib		=prim_list;
	if(print_node)	printf("\n\nNOTE:Create ref_lib %s successfully\n\n",p1->lib_name);
	return p1;
}

REF_LIBRARY *newRef_Lib_List(REF_LIBRARY *first_ref_lib){
	NEW_LIST(REF_LIBRARY,p1);
	p1->list_cnt        =1;
	strcpy(p1->lib_name,first_ref_lib->lib_name);
	p1->cell_count		=first_ref_lib->cell_count;
	p1->prim_in_lib		=first_ref_lib->prim_in_lib;
	free(first_ref_lib);
	if(print_node)	printf("\n\nNOTE:New ref_lib list successfully\n\n");
	return p1;
}
REF_LIBRARY *newRef_Lib_List_Entry(REF_LIBRARY *existed_list,REF_LIBRARY *new_entry,int list_cnt){
	REF_LIBRARY *p1;
	NEW_ENTRY(REF_LIBRARY,existed_list,list_cnt,p1);
	p1->list_cnt 		=list_cnt;
	REF_LIBRARY *p2;
	p2=p1+list_cnt-1;
	strcpy(p2->lib_name,new_entry->lib_name);
	p2->cell_count		=new_entry->list_cnt;
	p2->prim_in_lib		=new_entry->prim_in_lib;
	if(print_node)	printf("\n\nNOTE:Add a ref_lib %s successfully\n\n",p2->lib_name);
	free(new_entry);
	return p1;
}



//-----------------------------------------------------------------------------------------------------------
//构建一个INSTANCE或者INSTANCE_LIST的函数
//-----------------------------------------------------------------------------------------------------------
PROPERTY *createProperty(char *property_id,char *property_type, char *property_value){
	NEW_LIST(PROPERTY,p1);
	SAFE_STRCPY(p1->property_id,	property_id,	MAX_PRIM_ID_LENGTH);	
	SAFE_STRCPY(p1->property_type,	property_type,	MAX_PRIM_ID_LENGTH);
	SAFE_STRCPY((p1->property_value).property_string_value,	property_value,	MAX_PRIM_ID_LENGTH);
	return p1;
}
PROPERTY *createProperty_Integer(char *property_id,char *property_type, int property_value){
	NEW_LIST(PROPERTY,p1);
	SAFE_STRCPY(p1->property_id,	property_id,	MAX_PRIM_ID_LENGTH);	
	SAFE_STRCPY(p1->property_type,	property_type,	MAX_PRIM_ID_LENGTH);
	p1->property_value.property_num_value=property_value;
	return p1;
}

PROPERTY *newProperty_List(PROPERTY *first_property){
	NEW_LIST(PROPERTY,p1);
	strcpy(p1->property_id,	    first_property->property_id);	
	strcpy(p1->property_type,	first_property->property_type);
	int tmp;
	tmp=(!strcmp(first_property->property_type,"string"))?1:(!strcmp(first_property->property_type,"integer"))?2:3;
	switch(tmp)
	{
		case(1) :{
					strcpy(p1->property_value.property_string_value,first_property->property_value.property_string_value);
					break;
					}
		case(2):{
					p1->property_value.property_num_value=first_property->property_value.property_num_value;
					break;
				}
		default:{printf("Warning:Find a property is neither integer nor string\n");exit(1);}
	}
	free(first_property);
	return p1;
}

PROPERTY *newProperty_List_Entry(PROPERTY *existed_list, PROPERTY *new_entry, int list_cnt){
	PROPERTY *p1;
	NEW_ENTRY(PROPERTY,existed_list,list_cnt,p1);
	p1->list_cnt=list_cnt;
	PROPERTY *p2;
	p2=p1+list_cnt-1;
	strcpy(p2->property_id,	    new_entry->property_id);	
	strcpy(p2->property_type,	new_entry->property_type);
	int tmp;
	tmp=(!strcmp(new_entry->property_type,"string"))?1:(!strcmp(new_entry->property_type,"integer"))?2:3;
	switch(tmp)
	{
		case(1) :strcpy(p1->property_value.property_string_value,new_entry->property_value.property_string_value);break;
		case(2):p1->property_value.property_num_value=new_entry->property_value.property_num_value;break;
		default:printf("Warning:Find a property is neither integer nor string\n");exit(1);
	}
	free(new_entry);
	return p1;
}

VIEW_CELL_LIB_REF *decideInstance_Ref(char *viewref_id,char *cellref_id, char *libref_id){
	NEW_LIST(VIEW_CELL_LIB_REF,p1);
	SAFE_STRCPY(p1->viewref_id,viewref_id,MAX_PRIM_ID_LENGTH);
	SAFE_STRCPY(p1->cellref_id,cellref_id,MAX_PRIM_ID_LENGTH);
	SAFE_STRCPY(p1->libref_id, libref_id,MAX_USER_ID_LENGTH);
	return p1;
}

INSTANCE *createInstance(char *name, VIEW_CELL_LIB_REF *view_cell_lib_id, PROPERTY * p_instance_property){
	NEW_LIST(INSTANCE,p1);
	VIEW_CELL_LIB_REF *tmp;
	tmp=view_cell_lib_id;	
		//INSTANCE的类型是有限种的,根据它的view_cell_lib_ref的信息来判断是什么类型.
		//类型 用一个整数来表示
		if(strcmp(tmp->libref_id,"work")==0)
			p1->instance_type=3;
		else if(strcmp(tmp->viewref_id,"PRIM")==0)
			p1->instance_type=1;
		else 
			p1->instance_type=2;
	SAFE_STRCPY(p1->name,name,MAX_USER_ID_LENGTH);
	
	//INSTANCE内部包含的两个指针型变量	
	p1->view_cell_lib_id    =view_cell_lib_id;
	if(p_instance_property!=NULL)
		p1->p_instance_property =p_instance_property;
	else p1->p_instance_property=NULL;
	return p1;	
}

INSTANCE *newInstance_List(INSTANCE *first_instance){
	INSTANCE *p1;
	p1=first_instance;
	p1->list_cnt=1;
	return p1;
}

INSTANCE *newInstance_List_Entry(INSTANCE *existed_list, INSTANCE *new_entry,int list_cnt){
	INSTANCE *p1;
	NEW_ENTRY(INSTANCE,existed_list,list_cnt,p1);
	INSTANCE *p2;

	p1->list_cnt=list_cnt;
	p2=p1+list_cnt-1;
	if(strcmp((new_entry->view_cell_lib_id)->libref_id,"work")==0)
		p2->instance_type=3;
	else if(strcmp((new_entry->view_cell_lib_id)->viewref_id,"PRIM")==0)
		p2->instance_type=1;
	else 
		p2->instance_type=2;

	strcpy(p2->name,new_entry->name);	
	p2->view_cell_lib_id        =new_entry->view_cell_lib_id;
	
	if((new_entry->p_instance_property)!=NULL)
		p2->p_instance_property =new_entry->p_instance_property;
	else p2->p_instance_property=NULL;

	free(new_entry);
	return p1;
	
}


//-----------------------------------------------------------------------------------------------------------
//构建NET的函数
//-----------------------------------------------------------------------------------------------------------

PORTREF *createPortref(int portref_type,char *portref_id,int bit_location,char *instanceref_id){
		NEW_LIST(PORTREF,p1);
		//存在bug,因为传进来的instanceref_id可能会是一个NULL指针,所以必须carefully
		p1->portref_type =portref_type;
		SAFE_STRCPY(p1->portref_id,portref_id,MAX_PRIM_ID_LENGTH);		
		if (instanceref_id!=NULL){
		SAFE_STRCPY(p1->instanceref_id,instanceref_id,MAX_USER_ID_LENGTH);
		}		
		p1->bit_location=bit_location;
		return p1;		
}	
PORTREF *newPortref_List(PORTREF *first_portref){
		NEW_LIST(PORTREF,p1);		
		p1->portref_type	=first_portref->portref_type;
		strcpy(p1->portref_id,first_portref->portref_id);	
		p1->bit_location    =first_portref->bit_location;
		strcpy(p1->instanceref_id,first_portref->instanceref_id);
		free(first_portref);
		return p1;	
}

PORTREF *newPortref_List_Entry(PORTREF *existed_list,PORTREF *new_entry,int list_cnt){
		
		PORTREF *p1;
		NEW_ENTRY(PORTREF,existed_list,list_cnt,p1);		
		p1->list_cnt=list_cnt;
		PORTREF *p2;
		p2=p1+list_cnt-1;		
		p2->portref_type	=new_entry->portref_type;
		strcpy(p2->portref_id,new_entry->portref_id);
		p2->bit_location    =new_entry->bit_location;
		strcpy(p2->instanceref_id,new_entry->instanceref_id);
		free(new_entry);	
		return p1;
}


NET *findNet(char *net_name,PORTREF *portref_list){
	NEW_LIST(NET,p1);
	SAFE_STRCPY(p1->net_name,net_name,MAX_USER_ID_LENGTH);
	p1->portref_number=portref_list->list_cnt;
	p1->portref_list  =portref_list;
	return p1;
}



NET *newNet_List(NET *first_net){
	NEW_LIST(NET,p1);
	strcpy(p1->net_name,first_net->net_name);
	p1->portref_number=first_net->portref_number;
	p1->portref_list  =first_net->portref_list;
	free(first_net);
	return p1;	
}

NET *newNet_List_Entry(NET *existed_list,NET *new_entry,int list_cnt){
	NET *p1;
	NEW_ENTRY(NET,existed_list,list_cnt,p1);
	p1->list_cnt=list_cnt;
	NET *p2;
	p2=p1+list_cnt-1;
	strcpy(p2->net_name,new_entry->net_name);
	p2->portref_number=new_entry->portref_number;
	p2->portref_list  =new_entry->portref_list;
	free(new_entry);
	return p1;
}

//-----------------------------------------------------------------------------------------------------------
//构建工作库中的CELL的函数
//-----------------------------------------------------------------------------------------------------------

VIEW  *createView(char *view ,int viewtype,PORT *interface,INSTANCE *instance_list,NET *net_list ,PROPERTY *property_list){
	VIEW *p1;
	p1=(VIEW *)malloc(sizeof(VIEW));
	int tmp;
	tmp=strcmp(view,"netlist")?1:strcmp(view,"verilog")?2:3;
	p1->view=tmp;
	p1->viewtype=viewtype;
	p1->port_number=interface->list_cnt;
	p1->interface=interface;
	p1->instance_number=instance_list->list_cnt;
	p1->instance_list=instance_list;
	p1->net_number=net_list->list_cnt;
	p1->net_list=net_list;
	p1->property_number=property_list->list_cnt;
	p1->property_list=property_list;
	return p1;
} 
CELL *createCell(char *cell,int celltype,VIEW *view){
	CELL *p1;
	p1=(CELL *)malloc(sizeof(CELL));
	SAFE_STRCPY(p1->cell,cell,MAX_PRIM_ID_LENGTH);
	p1->celltype=celltype;
	p1->view=view;
	return p1;
}
CELL *newCell_List(CELL *first_cell){
	CELL *p1;
	p1=first_cell;
	p1->list_cnt=1;
	return p1;
}
CELL *newCell_List_Entry(CELL *existed_list,CELL *new_entry,int list_cnt){
	CELL *p1;
	NEW_ENTRY(CELL,existed_list,list_cnt,p1);
	p1->list_cnt=list_cnt;
	CELL *p2;
	p2=p1+list_cnt-1;
	strcpy(p2->cell,new_entry->cell);
	p2->celltype=new_entry->celltype;
	p2->view=new_entry->view;
	free(new_entry);
	return p1;
}


