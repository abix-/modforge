// Address: 0x14018cd90
// Ghidra name: FUN_14018cd90
// ============ 0x14018cd90 FUN_14018cd90 (size=314) ============


LRESULT FUN_14018cd90(int param_1,WPARAM param_2,uint *param_3)



{

  uint uVar1;

  longlong lVar2;

  LRESULT LVar3;

  undefined8 uVar4;

  

  lVar2 = FUN_14016dcf0();

  lVar2 = *(longlong *)(lVar2 + 0x680);

  if (param_1 == 0) {

    uVar1 = param_3[1];

    if (uVar1 != 0x21d) {

      switch(*param_3) {

      case 9:

        uVar4 = 0x2b;

        break;

      default:

        goto switchD_14018cdfa_caseD_a;

      case 0x1b:

        uVar4 = 0x29;

        break;

      case 0x2c:

        uVar4 = 0x46;

        break;

      case 0x5b:

        uVar4 = 0xe3;

        break;

      case 0x5c:

        uVar4 = 0xe7;

        break;

      case 0xa2:

        uVar4 = 0xe0;

        break;

      case 0xa3:

        uVar4 = 0xe4;

        break;

      case 0xa4:

        uVar4 = 0xe2;

        break;

      case 0xa5:

        uVar4 = 0xe6;

      }

      if ((param_2 - 0x100 & 0xfffffffffffffffb) == 0) {

        if (*(char *)(lVar2 + 0x129) == '\0') {

          FUN_140183990(0,0,uVar1,uVar4,1);

        }

      }

      else {

        if (*(char *)(lVar2 + 0x129) == '\0') {

          FUN_140183990(0,0,uVar1,uVar4,0);

        }

        uVar1 = *param_3;

        if ((uVar1 < 0x100) && (*(char *)((ulonglong)uVar1 + 0x288 + lVar2) != '\0')) {

          *(undefined1 *)((ulonglong)uVar1 + 0x288 + lVar2) = 0;

switchD_14018cdfa_caseD_a:

          param_1 = 0;

          goto LAB_14018cea7;

        }

      }

    }

    LVar3 = 1;

  }

  else {

LAB_14018cea7:

    LVar3 = CallNextHookEx((HHOOK)0x0,param_1,param_2,(LPARAM)param_3);

  }

  return LVar3;

}




