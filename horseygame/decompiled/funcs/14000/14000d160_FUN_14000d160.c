// Address: 0x14000d160
// Ghidra name: FUN_14000d160
// ============ 0x14000d160 FUN_14000d160 (size=229) ============


void FUN_14000d160(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

                  int param_5)



{

  longlong lVar1;

  int iVar2;

  undefined **local_48;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 local_2c;

  undefined2 local_18;

  

  if (*(int *)(param_1 + 0x18) <= param_5) {

    FID_conflict__assert

              (L"childIndex < m_count",

               L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.cpp",0x81);

  }

  lVar1 = *(longlong *)(param_1 + 0x10);

  local_48 = b2EdgeShape::vftable;

  local_40 = 1;

  local_38 = *(undefined4 *)(lVar1 + (longlong)param_5 * 8);

  local_34 = *(undefined4 *)(lVar1 + 4 + (longlong)param_5 * 8);

  iVar2 = 0;

  if (param_5 + 1 != *(int *)(param_1 + 0x18)) {

    iVar2 = param_5 + 1;

  }

  local_3c = 0x3c23d70a;

  local_30 = *(undefined4 *)(lVar1 + (longlong)iVar2 * 8);

  local_2c = *(undefined4 *)(lVar1 + 4 + (longlong)iVar2 * 8);

  local_18 = 0;

  FUN_14000c9b0(&local_48,param_2,param_3,param_4,0);

  return;

}




