// Address: 0x1401427d0
// Ghidra name: FUN_1401427d0
// ============ 0x1401427d0 FUN_1401427d0 (size=364) ============


ulonglong FUN_1401427d0(char *param_1,code *param_2,undefined8 param_3)



{

  byte bVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  undefined8 *puVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    if (param_2 == (code *)0x0) {

      uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","callback");

      return uVar2;

    }

    uVar3 = FUN_1401426c0(1);

    uVar7 = uVar3 & 0xffffffff;

    uVar2 = uVar3;

    if ((int)uVar3 != 0) {

      puVar4 = (undefined8 *)FUN_1401841f0(0x18);

      uVar2 = 0;

      if (puVar4 != (undefined8 *)0x0) {

        *puVar4 = param_2;

        puVar4[1] = param_3;

        FUN_140175050(uVar7);

        FUN_140142b00(param_1,param_2,param_3);

        puVar5 = (undefined8 *)FUN_140174d30(uVar3 & 0xffffffff,param_1,0);

        if (puVar5 == (undefined8 *)0x0) {

          puVar5 = (undefined8 *)FUN_1401841f0(0x18);

          if (puVar5 == (undefined8 *)0x0) {

            FUN_1401841e0(puVar4);

            uVar2 = FUN_1401755c0(uVar7);

            return uVar2 & 0xffffffffffffff00;

          }

          *puVar5 = 0;

          *(undefined4 *)(puVar5 + 1) = 0;

          puVar5[2] = 0;

          bVar1 = FUN_1401753d0(uVar7,param_1,puVar5,FUN_1401425e0,0);

        }

        else {

          bVar1 = 1;

        }

        puVar4[2] = puVar5[2];

        puVar5[2] = puVar4;

        uVar6 = FUN_140142960(param_1);

        (*param_2)(param_3,param_1,uVar6,uVar6);

        FUN_1401755c0(uVar7);

        return (ulonglong)bVar1;

      }

    }

    return uVar2 & 0xffffffffffffff00;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140304430);

  return uVar2;

}




