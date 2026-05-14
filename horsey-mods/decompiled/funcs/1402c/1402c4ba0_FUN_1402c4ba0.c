// Address: 0x1402c4ba0
// Ghidra name: FUN_1402c4ba0
// ============ 0x1402c4ba0 FUN_1402c4ba0 (size=133) ============


longlong FUN_1402c4ba0(undefined8 *param_1,undefined4 param_2)



{

  longlong lVar1;

  

  FUN_140179b40(*param_1);

  lVar1 = param_1[0x10];

  if (lVar1 == 0) {

    FUN_140163d20(param_1[1],*param_1,param_2);

    lVar1 = param_1[0x10];

    if (lVar1 == 0) goto LAB_1402c4c0a;

  }

  if (*(longlong *)(lVar1 + 0x70) != 0) {

    *(undefined8 *)(*(longlong *)(lVar1 + 0x70) + 0x68) = *(undefined8 *)(lVar1 + 0x68);

  }

  *(undefined8 *)(*(longlong *)(lVar1 + 0x68) + 0x70) = *(undefined8 *)(lVar1 + 0x70);

  *(undefined8 *)(lVar1 + 0x70) = 0;

  *(undefined8 *)(lVar1 + 0x68) = 0;

LAB_1402c4c0a:

  FUN_140179b60(*param_1);

  return lVar1;

}




