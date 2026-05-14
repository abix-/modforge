// Address: 0x1402079c0
// Ghidra name: FUN_1402079c0
// ============ 0x1402079c0 FUN_1402079c0 (size=267) ============


void FUN_1402079c0(char *param_1,undefined1 *param_2,int param_3)



{

  int iVar1;

  size_t sVar2;

  longlong lVar3;

  longlong lVar4;

  uint uVar5;

  longlong lVar6;

  

  sVar2 = strlen(param_1);

  lVar6 = (longlong)(param_3 * 10) + 2 +

          sVar2 + (longlong)(((int)(param_3 + (param_3 >> 0x1f & 7U)) >> 3) * 0xb);

  lVar3 = FUN_1401841f0(lVar6);

  iVar1 = FUN_14012ef10(lVar3,lVar6,param_1,param_3);

  uVar5 = 0;

  lVar4 = (longlong)iVar1;

  if (0 < param_3) {

    do {

      if ((uVar5 & 7) == 0) {

        iVar1 = FUN_14012ef10(lVar4 + lVar3,lVar6 - lVar4,"\n%.2d:      ",uVar5);

        lVar4 = lVar4 + iVar1;

      }

      iVar1 = FUN_14012ef10(lVar4 + lVar3,lVar6 - lVar4," 0x%.2x",*param_2);

      uVar5 = uVar5 + 1;

      lVar4 = lVar4 + iVar1;

      param_2 = param_2 + 1;

    } while ((int)uVar5 < param_3);

  }

  FUN_14012f120(lVar3,&DAT_14039bd10,lVar6);

  FUN_14012e080(7,&DAT_14039bf30,lVar3);

  FUN_1401841e0(lVar3);

  return;

}




