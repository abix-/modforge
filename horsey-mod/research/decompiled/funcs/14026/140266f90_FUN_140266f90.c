// Address: 0x140266f90
// Ghidra name: FUN_140266f90
// ============ 0x140266f90 FUN_140266f90 (size=440) ============


ulonglong FUN_140266f90(longlong param_1,byte *param_2,undefined8 param_3,int param_4)



{

  char cVar1;

  ulonglong uVar2;

  char *pcVar3;

  uint uVar4;

  

  if ((((*(char *)(param_1 + 8) != '\0') && (*(int *)(param_1 + 0x144) == -1)) && (*param_2 == 0xb))

     && (param_4 == 8)) {

    if (*(int *)(param_1 + 0x10) == 0) {

      *(int *)(param_1 + 0x10) = (int)param_1;

      FUN_140182e30(param_1,"Xbox One Chatpad");

    }

    *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 0x800;

    *(undefined4 *)(param_1 + 0x144) = 5;

  }

  uVar4 = (uint)*param_2;

  cVar1 = FUN_1402680b0(param_1,*param_2,1);

  if (cVar1 == '\0') {

    pcVar3 = "GIP: Received claimed-unsupported system message type %02x";

LAB_140267124:

    uVar2 = FUN_14012e2e0(7,pcVar3,uVar4);

    uVar2 = uVar2 & 0xffffffffffffff00;

  }

  else {

    switch(uVar4) {

    case 1:

      uVar2 = FUN_140266190(param_1,param_2,param_3,param_4);

      break;

    case 2:

      uVar2 = FUN_1402657a0(param_1,param_2,param_3,param_4);

      break;

    case 3:

      uVar2 = FUN_140266350(param_1,param_2,param_3,param_4);

      break;

    case 4:

      uVar2 = FUN_140265cd0(param_1,param_2,param_3,param_4);

      break;

    default:

      pcVar3 = "GIP: Received unknown system message type %02x";

      goto LAB_140267124;

    case 6:

      uVar2 = FUN_140266330(param_1,param_2,param_3,param_4);

      break;

    case 7:

      uVar2 = FUN_140265720(param_1,param_2,param_3,param_4);

      break;

    case 8:

      uVar2 = FUN_140265560(param_1,param_2,param_3,param_4);

      break;

    case 0xb:

      uVar2 = FUN_140265a30(param_1,param_2,param_3,param_4);

      break;

    case 0xc:

      uVar2 = FUN_140265610(param_1,param_2,param_3,param_4);

      break;

    case 0x1e:

      uVar2 = FUN_140265580(param_1,param_2,param_3,param_4);

      break;

    case 0x60:

      uVar2 = FUN_140265540(param_1,param_2,param_3,param_4);

    }

  }

  return uVar2;

}




