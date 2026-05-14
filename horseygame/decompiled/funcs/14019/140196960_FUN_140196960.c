// Address: 0x140196960
// Ghidra name: FUN_140196960
// ============ 0x140196960 FUN_140196960 (size=70) ============


longlong FUN_140196960(int param_1,int param_2,char param_3,longlong *param_4)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  

  lVar3 = *param_4;

  iVar2 = *(int *)(*(longlong *)(lVar3 + 0x20) + 0x14);

  while( true ) {

    if (iVar2 == 3) {

      return lVar3;

    }

    plVar1 = (longlong *)(lVar3 + 0x20);

    lVar3 = *(longlong *)(lVar3 + 0x20);

    if ((*(int *)(lVar3 + 0x14) == 4) ||

       (((param_1 <= *(int *)(lVar3 + 4) && (*(char *)(lVar3 + 0x18) == param_3)) &&

        (*(int *)(lVar3 + 0x14) == param_2)))) break;

    iVar2 = *(int *)(*(longlong *)(lVar3 + 0x20) + 0x14);

    param_4 = plVar1;

  }

  return *param_4;

}




