// Address: 0x140101570
// Ghidra name: FUN_140101570
// ============ 0x140101570 FUN_140101570 (size=116) ============


bool FUN_140101570(longlong param_1,undefined8 param_2,uint param_3)



{

  int iVar1;

  int iVar2;

  float local_res20;

  float fStackX_24;

  

  local_res20 = (float)param_2;

  iVar2 = (int)(local_res20 * DAT_140303fb4);

  fStackX_24 = (float)((ulonglong)param_2 >> 0x20);

  iVar1 = (int)(fStackX_24 * DAT_140303fb4);

  if (-1 < iVar2) {

    if (((iVar2 < *(int *)(param_1 + 0x278)) && (-1 < iVar1)) && (iVar1 < *(int *)(param_1 + 0x27c))

       ) {

      return (*(uint *)(&DAT_1403132d4 +

                       (longlong)

                       *(int *)(*(longlong *)(param_1 + 0x270) +

                               (longlong)(*(int *)(param_1 + 0x278) * iVar1 + iVar2) * 0x28) * 0x1c)

             & param_3) != 0;

    }

  }

  return true;

}




