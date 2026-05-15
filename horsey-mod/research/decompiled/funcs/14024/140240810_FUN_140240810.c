// Address: 0x140240810
// Ghidra name: FUN_140240810
// ============ 0x140240810 FUN_140240810 (size=358) ============


bool FUN_140240810(undefined8 *param_1,int param_2,undefined4 *param_3)



{

  longlong lVar1;

  char cVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  undefined1 *puVar7;

  undefined1 local_28 [16];

  

  if (param_2 == 0) {

    return true;

  }

  (*(code *)*param_1)();

  lVar1 = (longlong)param_2 * 0x18;

  pcVar6 = 

  "#define sampler2D sampler2DRect\n#define texture2D texture2DRect\n#define UVCoordScale 0.5\n";

  if (*(char *)(param_1 + 0x10) == '\0') {

    pcVar6 = "#define UVCoordScale 1.0\n";

  }

  puVar7 = &DAT_14039bcb9;

  if (*(undefined1 **)(&DAT_1403e5660 + lVar1) != (undefined1 *)0x0) {

    puVar7 = *(undefined1 **)(&DAT_1403e5660 + lVar1);

  }

  uVar3 = (*(code *)param_1[3])();

  *param_3 = uVar3;

  uVar3 = (*(code *)param_1[4])(0x8b31);

  param_3[1] = uVar3;

  cVar2 = FUN_140240690(param_1,uVar3,&DAT_14039bcb9,&DAT_14039bcb9,

                        *(undefined8 *)(&DAT_1403e5650 + lVar1));

  if (cVar2 != '\0') {

    uVar3 = (*(code *)param_1[4])(0x8b30);

    param_3[2] = uVar3;

    cVar2 = FUN_140240690(param_1,uVar3,puVar7,pcVar6,*(undefined8 *)(&DAT_1403e5658 + lVar1));

    if (cVar2 != '\0') {

      (*(code *)param_1[1])(*param_3,param_3[1]);

      (*(code *)param_1[1])(*param_3,param_3[2]);

      (*(code *)param_1[9])(*param_3);

      (*(code *)param_1[0xf])(*param_3);

      iVar5 = 0;

      do {

        FUN_14012ef10(local_28,10,"tex%d",iVar5);

        iVar4 = (*(code *)param_1[8])(*param_3,local_28);

        if (-1 < iVar4) {

          (*(code *)param_1[0xb])(iVar4,iVar5);

        }

        iVar5 = iVar5 + 1;

      } while (iVar5 < 4);

      (*(code *)param_1[0xf])(0);

      iVar5 = (*(code *)*param_1)();

      return iVar5 == 0;

    }

  }

  return false;

}




