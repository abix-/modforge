// Address: 0x14025faf0
// Ghidra name: FUN_14025faf0
// ============ 0x14025faf0 FUN_14025faf0 (size=387) ============


undefined8 FUN_14025faf0(longlong param_1,int *param_2,int param_3,undefined4 param_4)



{

  char cVar1;

  undefined8 uVar2;

  code *pcVar3;

  longlong lVar4;

  int *piVar5;

  longlong lVar6;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  

  lVar4 = (longlong)param_3;

  cVar1 = FUN_1401489c0();

  if (cVar1 != '\0') {

    pcVar3 = (code *)FUN_14025ec50(*(undefined8 *)(param_1 + 0x38));

    if (pcVar3 == (code *)0x0) {

      uVar2 = FUN_14012e850("SDL_DrawLines(): Unsupported surface format");

    }

    else {

      if (1 < lVar4) {

        lVar6 = lVar4 + -1;

        piVar5 = param_2 + 3;

        do {

          local_30 = piVar5[-3];

          local_38 = piVar5[-2];

          local_2c = piVar5[-1];

          local_34 = *piVar5;

          cVar1 = FUN_140184d90(param_1 + 100,&local_30,&local_38,&local_2c,&local_34);

          if (cVar1 != '\0') {

            (*pcVar3)(param_1);

          }

          piVar5 = piVar5 + 2;

          lVar6 = lVar6 + -1;

        } while (lVar6 != 0);

      }

      lVar4 = lVar4 + -1;

      if ((*param_2 != param_2[lVar4 * 2]) || (param_2[1] != param_2[lVar4 * 2 + 1])) {

        FUN_14025fc80(param_1,param_2[lVar4 * 2],param_2[lVar4 * 2 + 1],param_4);

      }

      uVar2 = 1;

    }

    return uVar2;

  }

  uVar2 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_DrawLines(): dst");

  return uVar2;

}




