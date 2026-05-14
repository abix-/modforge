// Address: 0x140208230
// Ghidra name: FUN_140208230
// ============ 0x140208230 FUN_140208230 (size=256) ============


void FUN_140208230(longlong param_1,int param_2)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  longlong lVar5;

  

  FUN_140159d30();

  cVar1 = FUN_140208330(param_1,param_2);

  if (cVar1 == '\0') {

    param_1 = *(longlong *)(param_1 + 0xa0);

  }

  iVar4 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar5 = 0;

    do {

      if (*(int *)(lVar5 + *(longlong *)(param_1 + 0x90)) == param_2) {

        lVar2 = FUN_1401581c0(param_2);

        if (lVar2 != 0) {

          FUN_140206750(lVar2);

        }

        FUN_140207890(param_1,param_2);

        iVar3 = 0;

        if (0 < *(int *)(param_1 + 0xa8)) {

          lVar2 = 0;

          do {

            FUN_140207890(*(undefined8 *)(*(longlong *)(param_1 + 0xb0) + lVar2),param_2);

            iVar3 = iVar3 + 1;

            lVar2 = lVar2 + 8;

          } while (iVar3 < *(int *)(param_1 + 0xa8));

        }

        DAT_1403fd1a0 = DAT_1403fd1a0 + -1;

        if (DAT_1403fd195 == '\0') {

          FUN_14015a550(param_2);

        }

      }

      iVar4 = iVar4 + 1;

      lVar5 = lVar5 + 4;

    } while (iVar4 < *(int *)(param_1 + 0x8c));

  }

  DAT_1403fd190 = 0;

  FUN_14015bb10();

  return;

}




