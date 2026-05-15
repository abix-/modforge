// Address: 0x1401711e0
// Ghidra name: FUN_1401711e0
// ============ 0x1401711e0 FUN_1401711e0 (size=366) ============


ulonglong FUN_1401711e0(longlong param_1,int param_2,int param_3)



{

  code *pcVar1;

  char cVar2;

  ulonglong uVar3;

  longlong lVar4;

  int iVar5;

  int iVar6;

  bool bVar7;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar2 = FUN_1401aa7c0(param_1,1), cVar2 == '\0')))) {

    uVar3 = FUN_14012e850("Invalid window");

    return uVar3 & 0xffffffffffffff00;

  }

  lVar4 = DAT_1403fc410;

  if (param_2 < 0) {

    uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","max_w");

    return uVar3;

  }

  if (-1 < param_3) {

    if (((param_2 == 0) || (*(int *)(param_1 + 0x28) <= param_2)) &&

       ((param_3 == 0 || (*(int *)(param_1 + 0x2c) <= param_3)))) {

      *(int *)(param_1 + 0x30) = param_2;

      *(int *)(param_1 + 0x34) = param_3;

      pcVar1 = *(code **)(lVar4 + 0x78);

      if (pcVar1 != (code *)0x0) {

        (*pcVar1)(lVar4,param_1);

        param_2 = *(int *)(param_1 + 0x30);

        param_3 = *(int *)(param_1 + 0x34);

      }

      bVar7 = *(char *)(param_1 + 0x10c) == '\0';

      lVar4 = 0x98;

      if (bVar7) {

        lVar4 = 0x88;

      }

      iVar6 = *(int *)(lVar4 + param_1);

      lVar4 = 0x94;

      if (bVar7) {

        lVar4 = 0x84;

      }

      iVar5 = *(int *)(lVar4 + param_1);

      if ((param_2 != 0) && (param_2 <= iVar5)) {

        iVar5 = param_2;

      }

      if ((param_3 != 0) && (param_3 <= iVar6)) {

        iVar6 = param_3;

      }

      uVar3 = FUN_140172190(param_1,iVar5,iVar6);

      return uVar3;

    }

    uVar3 = FUN_14012e850(

                         "SDL_SetWindowMaximumSize(): Tried to set maximum size smaller than minimum size"

                         );

    return uVar3;

  }

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid","max_h");

  return uVar3;

}




