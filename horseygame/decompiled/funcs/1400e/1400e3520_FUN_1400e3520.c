// Address: 0x1400e3520
// Ghidra name: FUN_1400e3520
// ============ 0x1400e3520 FUN_1400e3520 (size=153) ============


int FUN_1400e3520(longlong param_1,longlong *param_2)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  int iVar5;

  

  lVar1 = *param_2;

  lVar4 = FUN_1400c7520(*(undefined4 *)(lVar1 + 0x1f8));

  cVar2 = FUN_1400b7660(lVar1,0,0);

  if (((cVar2 != '\0') && (lVar1 != *(longlong *)(*(longlong *)(param_1 + 8) + 0x148))) &&

     (*(int *)(lVar4 + 0x54) != 0)) {

    iVar5 = 400;

    if (*(char *)(lVar4 + 0x58) == '\0') {

      iVar5 = *(int *)(lVar4 + 0x54) * 100;

    }

    lVar1 = *(longlong *)(lVar4 + 0x78);

    lVar4 = *(longlong *)(lVar4 + 0x70);

    iVar3 = FUN_1400c6580(10);

    return iVar3 + iVar5 + (int)(lVar1 - lVar4 >> 2) * 10;

  }

  return -1;

}




