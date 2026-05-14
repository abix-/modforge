// Address: 0x14016df60
// Ghidra name: FUN_14016df60
// ============ 0x14016df60 FUN_14016df60 (size=231) ============


ulonglong FUN_14016df60(longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4

                       ,undefined4 *param_5)



{

  char cVar1;

  ulonglong uVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  undefined4 local_res10 [2];

  

  local_res10[0] = 0;

  puVar4 = local_res10;

  if (param_2 != (undefined4 *)0x0) {

    puVar4 = param_2;

  }

  puVar3 = local_res10;

  if (param_3 != (undefined4 *)0x0) {

    puVar3 = param_3;

  }

  puVar5 = local_res10;

  if (param_5 != (undefined4 *)0x0) {

    puVar5 = param_5;

  }

  puVar6 = local_res10;

  if (param_4 != (undefined4 *)0x0) {

    puVar6 = param_4;

  }

  *puVar5 = 0;

  *puVar6 = 0;

  *puVar3 = 0;

  *puVar4 = 0;

  if (DAT_1403fc410 == 0) {

    uVar2 = FUN_1401730c0();

  }

  else {

    if ((param_1 != 0) &&

       ((DAT_1403e3d60 == '\0' || (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 != '\0')))) {

      if (*(code **)(DAT_1403fc410 + 0x88) == (code *)0x0) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

      uVar2 = (**(code **)(DAT_1403fc410 + 0x88))(DAT_1403fc410,param_1,puVar4,puVar3,puVar6,puVar5)

      ;

      return uVar2;

    }

    uVar2 = FUN_14012e850("Invalid window");

  }

  return uVar2 & 0xffffffffffffff00;

}




