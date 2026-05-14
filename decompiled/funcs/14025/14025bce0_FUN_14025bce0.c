// Address: 0x14025bce0
// Ghidra name: FUN_14025bce0
// ============ 0x14025bce0 FUN_14025bce0 (size=480) ============


undefined8

FUN_14025bce0(longlong param_1,int *param_2,int param_3,undefined4 param_4,undefined1 param_5,

             undefined1 param_6,undefined1 param_7,undefined1 param_8)



{

  char cVar1;

  undefined1 uVar2;

  undefined8 uVar3;

  code *pcVar4;

  int *piVar5;

  longlong lVar6;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  

  cVar1 = FUN_1401489c0();

  if (cVar1 != '\0') {

    pcVar4 = (code *)FUN_14025bec0(*(undefined8 *)(param_1 + 0x38));

    if (pcVar4 == (code *)0x0) {

      uVar3 = FUN_14012e850("SDL_BlendLines(): Unsupported surface format");

    }

    else {

      if (1 < (longlong)param_3) {

        piVar5 = param_2 + 3;

        lVar6 = (longlong)param_3 + -1;

        do {

          local_3c = piVar5[-3];

          local_40 = piVar5[-2];

          local_44 = piVar5[-1];

          local_48 = *piVar5;

          cVar1 = FUN_140184d90(param_1 + 100,&local_3c,&local_40,&local_44,&local_48);

          if (cVar1 != '\0') {

            if ((local_44 == piVar5[-1]) && (local_48 == *piVar5)) {

              uVar2 = 0;

            }

            else {

              uVar2 = 1;

            }

            (*pcVar4)(param_1,local_3c,local_40,local_44,local_48,param_4,param_5,param_6,param_7,

                      param_8,uVar2);

          }

          piVar5 = piVar5 + 2;

          lVar6 = lVar6 + -1;

        } while (lVar6 != 0);

      }

      lVar6 = (longlong)param_3;

      if ((*param_2 != param_2[lVar6 * 2 + -2]) || (param_2[1] != param_2[lVar6 * 2 + -1])) {

        FUN_14025bf40(param_1,param_2[lVar6 * 2 + -2],param_2[lVar6 * 2 + -1],param_4,param_5,

                      param_6,param_7,param_8);

      }

      uVar3 = 1;

    }

    return uVar3;

  }

  uVar3 = FUN_14012e850("SDL_BlendLines(): Passed NULL destination surface");

  return uVar3;

}




