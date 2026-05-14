// Address: 0x1402017e0
// Ghidra name: FUN_1402017e0
// ============ 0x1402017e0 FUN_1402017e0 (size=171) ============


undefined8 FUN_1402017e0(undefined8 param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  longlong lVar4;

  undefined8 uVar5;

  

  lVar4 = FUN_1402002c0();

  cVar3 = FUN_1401489c0(lVar4);

  if (cVar3 != '\0') {

    iVar1 = *param_2;

    if ((((-1 < iVar1) && (param_2[2] + iVar1 <= *(int *)(lVar4 + 8))) &&

        (iVar2 = param_2[1], -1 < iVar2)) && (param_2[3] + iVar2 <= *(int *)(lVar4 + 0xc))) {

      uVar5 = FUN_1401460c0(param_2[2],param_2[3],*(undefined4 *)(lVar4 + 4),0x120005a0,

                            (longlong)

                            (int)((uint)*(byte *)(*(longlong *)(lVar4 + 0x38) + 5) * iVar1) +

                            (longlong)(*(int *)(lVar4 + 0x10) * iVar2) + *(longlong *)(lVar4 + 0x18)

                            ,*(int *)(lVar4 + 0x10));

      return uVar5;

    }

    FUN_14012e850("Tried to read outside of surface bounds");

  }

  return 0;

}




