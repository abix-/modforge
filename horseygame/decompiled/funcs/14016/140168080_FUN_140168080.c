// Address: 0x140168080
// Ghidra name: FUN_140168080
// ============ 0x140168080 FUN_140168080 (size=522) ============


undefined1 FUN_140168080(undefined8 *param_1,undefined8 *param_2,undefined4 param_3,int param_4)



{

  undefined1 uVar1;

  char cVar2;

  undefined1 *puVar3;

  int iVar4;

  undefined1 *puVar5;

  undefined1 *puVar6;

  undefined8 *puVar7;

  undefined8 local_458;

  undefined4 local_450;

  undefined1 local_448 [32];

  undefined1 local_428 [1024];

  undefined4 uVar8;

  

  if (param_1 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","stream");

    return uVar1;

  }

  if (param_2 == (undefined8 *)0x0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","channel_buffers");

    return uVar1;

  }

  if (param_4 < 0) {

    uVar1 = FUN_14012e850("Parameter \'%s\' is invalid","num_samples");

    return uVar1;

  }

  if (param_4 != 0) {

    puVar5 = (undefined1 *)0x0;

    FUN_140179b40(*param_1);

    cVar2 = FUN_140163e40(param_1);

    if (cVar2 == '\0') {

      FUN_140179b60(*param_1);

      uVar1 = 0;

    }

    else {

      local_458 = param_1[6];

      local_450 = *(undefined4 *)(param_1 + 7);

      if (param_1[9] != 0) {

        puVar5 = local_448;

        FUN_1402f8e20(local_448,param_1[9],(longlong)(int)((ulonglong)local_458 >> 0x20) << 2);

      }

      FUN_140179b60(*param_1);

      if (local_458._4_4_ == 1) {

        uVar1 = FUN_140167f30(param_1,*param_2,((uint)local_458 >> 3 & 0x1f) * param_4);

      }

      else {

        puVar3 = local_428;

        puVar6 = (undefined1 *)0x0;

        iVar4 = ((uint)local_458 >> 3 & 0x1f) * local_458._4_4_ * param_4;

        if (0x400 < iVar4) {

          puVar3 = (undefined1 *)FUN_1401841f0((longlong)iVar4);

          if (puVar3 == (undefined1 *)0x0) {

            return 0;

          }

          puVar6 = &LAB_1401644d0;

        }

        puVar7 = &local_458;

        FUN_140164940(puVar3,param_2,param_3,param_4,puVar7);

        uVar8 = (undefined4)((ulonglong)puVar7 >> 0x20);

        FUN_140179b40(*param_1);

        uVar1 = FUN_140164f60(param_1,&local_458,puVar5,puVar3,CONCAT44(uVar8,iVar4),puVar6,0);

        FUN_140179b60(*param_1);

      }

    }

    return uVar1;

  }

  return 1;

}




