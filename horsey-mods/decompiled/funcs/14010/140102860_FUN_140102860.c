// Address: 0x140102860
// Ghidra name: FUN_140102860
// ============ 0x140102860 FUN_140102860 (size=346) ============


void FUN_140102860(longlong param_1,float param_2,float param_3,int param_4,int param_5,int param_6)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = param_4 * param_6 * 3;

  iVar4 = param_5 * param_6 * 3;

  iVar3 = (int)((float)((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2) + param_2 * DAT_140303fb4);

  iVar2 = 0;

  iVar4 = (int)((float)((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + param_3 * DAT_140303fb4);

  do {

    for (lVar1 = *(longlong *)

                  (*(longlong *)(param_1 + 0x270) + 0x10 +

                  (longlong)

                  (((&DAT_1403f4f38)[(longlong)iVar2 * 10] + iVar4) * *(int *)(param_1 + 0x278) +

                   (&DAT_1403f4f34)[(longlong)iVar2 * 10] + iVar3) * 0x28); lVar1 != 0;

        lVar1 = *(longlong *)(lVar1 + 0x58)) {

      if ((*(char *)(lVar1 + 0x11) == '\0') && (*(int *)(lVar1 + 8) == 0)) {

        FUN_140081d10(lVar1);

      }

    }

    iVar2 = FUN_140100a40(param_1,iVar2,iVar3,iVar4,param_6,0);

  } while (iVar2 != -1);

  return;

}




