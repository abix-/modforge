// Address: 0x1401f4660
// Ghidra name: FUN_1401f4660
// ============ 0x1401f4660 FUN_1401f4660 (size=172) ============


undefined1

FUN_1401f4660(char *param_1,longlong param_2,undefined8 param_3,undefined4 param_4,

             undefined8 param_5)



{

  longlong lVar1;

  int iVar2;

  undefined8 uVar3;

  undefined1 uVar4;

  

  lVar1 = *(longlong *)(param_2 + 0x2e0);

  uVar4 = 1;

  if ((*(char *)(lVar1 + 8) != '\0') && (iVar2 = (**(code **)(lVar1 + 200))(), iVar2 != 0)) {

    uVar4 = 0;

    do {

      if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {

        param_1 = "generic";

      }

      uVar3 = FUN_1401f4740(iVar2);

      FUN_14012e850("%s: %s (%d): %s %s (0x%X)",param_1,param_3,param_4,param_5,uVar3,iVar2);

      iVar2 = (**(code **)(lVar1 + 200))();

    } while (iVar2 != 0);

  }

  return uVar4;

}




