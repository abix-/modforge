// Address: 0x14013fef0
// Ghidra name: FUN_14013fef0
// ============ 0x14013fef0 FUN_14013fef0 (size=303) ============


void FUN_14013fef0(undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)



{

  int iVar1;

  undefined *puVar2;

  undefined *puVar3;

  undefined1 local_18 [16];

  

  if (*param_4 != 0) {

    FUN_14012f120(param_1,param_3,param_2);

    FUN_14012f120(param_1,&DAT_140331a70,param_2);

    iVar1 = *param_4;

    if (iVar1 == 1) {

      FUN_14012ef10(local_18,0x10,&DAT_140331a74,(char)param_4[1]);

    }

    else if (iVar1 == 2) {

      puVar2 = &DAT_14039bcb9;

      if (*(char *)((longlong)param_4 + 6) == '\0') {

        puVar3 = &DAT_14039bcb9;

        if (*(char *)((longlong)param_4 + 7) != '\0') {

          puVar3 = &DAT_14030db60;

        }

      }

      else {

        puVar3 = &DAT_140331a7c;

      }

      if (*(char *)((longlong)param_4 + 5) != '\0') {

        puVar2 = &DAT_140331a78;

      }

      FUN_14012ef10(local_18,0x10,"%sa%u%s",puVar3,(char)param_4[1],puVar2);

    }

    else if (iVar1 == 3) {

      FUN_14012ef10(local_18,0x10,"h%i.%i",*(byte *)(param_4 + 1) >> 4,*(byte *)(param_4 + 1) & 0xf)

      ;

    }

    FUN_14012f120(param_1,local_18,param_2);

    FUN_14012f120(param_1,&DAT_140331a5c,param_2);

  }

  return;

}




