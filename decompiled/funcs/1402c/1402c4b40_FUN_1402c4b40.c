// Address: 0x1402c4b40
// Ghidra name: FUN_1402c4b40
// ============ 0x1402c4b40 FUN_1402c4b40 (size=94) ============


longlong FUN_1402c4b40(undefined8 *param_1)



{

  longlong lVar1;

  

  FUN_140179b40(*param_1);

  lVar1 = param_1[0x10];

  if (lVar1 != 0) {

    if (*(longlong *)(lVar1 + 0x70) != 0) {

      *(undefined8 *)(*(longlong *)(lVar1 + 0x70) + 0x68) = *(undefined8 *)(lVar1 + 0x68);

    }

    *(undefined8 *)(*(longlong *)(lVar1 + 0x68) + 0x70) = *(undefined8 *)(lVar1 + 0x70);

    *(undefined8 *)(lVar1 + 0x70) = 0;

    *(undefined8 *)(lVar1 + 0x68) = 0;

  }

  FUN_140179b60(*param_1);

  return lVar1;

}




