#ifndef NODE_UTIL_H
#define NODE_UTIL_H

#include "type.h"

//最顶层的EDIF
top_EDIF *createEdif(char *edif_name,REF_LIBRARY *reflib_list,CELL *work_cells,char *design_name);

//前九个函数已经足够来创建各个参考库,因为每一个参考库中的cell都只含有interface,而没有含有contents和nets
PORT *createPort(int number,char *name,int dir);
PORT *newPort_List( PORT *first_port);
PORT *newPort_List_Entry(PORT *existed_list,PORT *new_entry,int port_number_now);

PRIM_CELL   *createPrim(char *cell,int cell_type,int view,int view_type,PORT *interface);
PRIM_CELL   *newPrim_List(PRIM_CELL *first_prim_cell);
PRIM_CELL   *newPrim_List_Entry(PRIM_CELL   *existed_list,PRIM_CELL   *new_entry,int list_cnt);

REF_LIBRARY *createRef_Lib(char *lib_name,PRIM_CELL *prim_list);
REF_LIBRARY *newRef_Lib_List(REF_LIBRARY *first_ref_lib);
REF_LIBRARY *newRef_Lib_List_Entry(REF_LIBRARY *existed_list,REF_LIBRARY *new_entry,int list_cnt);



//下面的函数开始创建work_library,首先开始创建INSTANCE的列表.
PROPERTY 		  *createProperty(char *property_id,char *property_type, char *property_value);
PROPERTY		  *createProperty_Integer(char *property_id,char *property_type, int property_value);
PROPERTY          *newProperty_List(PROPERTY *first_property);
PROPERTY 		  *newProperty_List_Entry(PROPERTY *existed_list, PROPERTY *new_entry, int list_cnt);


VIEW_CELL_LIB_REF *decideInstance_Ref(char *viewref_id,char *cellref_id, char *libref_id);

INSTANCE          *createInstance(char *name, VIEW_CELL_LIB_REF *view_cell_lib_id, PROPERTY * p_instance_property);
INSTANCE 		  *newInstance_List(INSTANCE *first_instance);
INSTANCE 		  *newInstance_List_Entry(INSTANCE *existed_list, INSTANCE *new_entry,int list_cnt);
//开始创建NET列表

PORTREF *createPortref(int portref_type,char *portref_id,int bit_location,char *instanceref_id);
PORTREF *newPortref_List(PORTREF *first_portref);
PORTREF *newPortref_List_Entry(PORTREF *existed_list,PORTREF *new_entry,int list_cnt);

NET *findNet(char *net_name,PORTREF *portref_list);
NET *newNet_List(NET *first_net);
NET *newNet_List_Entry(NET *existed_list,NET *new_entry,int list_cnt);

//开始创建cell列表;
VIEW *createView(char *view ,int viewtype,PORT *interface,INSTANCE *instance_list,NET *net_list ,PROPERTY *property_list);
CELL *createCell(char *cell,int celltype,VIEW *view);
CELL *newCell_List(CELL *first_cell);
CELL *newCell_List_Entry(CELL *existed_list,CELL *new_entry,int list_cnt);
#endif
