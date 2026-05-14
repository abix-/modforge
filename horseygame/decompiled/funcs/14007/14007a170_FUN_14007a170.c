// Address: 0x14007a170
// Ghidra name: FUN_14007a170
// ============ 0x14007a170 FUN_14007a170 (size=328) ============


undefined8 FUN_14007a170(undefined8 *param_1,int param_2,uint param_3,int param_4,longlong param_5)



{

  undefined4 uVar1;

  undefined8 uVar2;

  ulonglong uVar3;

  char local_e8 [8];

  char acStack_e0 [8];

  char local_d8 [8];

  char acStack_d0 [8];

  char local_c8 [4];

  char acStack_c4 [4];

  char acStack_c0 [4];

  char acStack_bc [4];

  char local_b8 [4];

  char acStack_b4 [4];

  char acStack_b0 [4];

  char acStack_ac [4];

  char local_a8 [16];

  undefined1 local_98 [128];

  

  uVar3 = (ulonglong)param_3;

  if ((((int)param_3 < 1) || (param_2 < 1)) || (param_5 == 0)) {

    uVar2 = 0;

  }

  else {

    uVar2 = _malloc_base((longlong)(param_2 * 4));

    local_a8[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x40];

    local_a8[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x41];

    local_e8[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0];

    local_e8[1] = s___RADIANCE___Written_by_stb_imag_14030a550[1];

    local_e8[2] = s___RADIANCE___Written_by_stb_imag_14030a550[2];

    local_e8[3] = s___RADIANCE___Written_by_stb_imag_14030a550[3];

    local_e8[4] = s___RADIANCE___Written_by_stb_imag_14030a550[4];

    local_e8[5] = s___RADIANCE___Written_by_stb_imag_14030a550[5];

    local_e8[6] = s___RADIANCE___Written_by_stb_imag_14030a550[6];

    local_e8[7] = s___RADIANCE___Written_by_stb_imag_14030a550[7];

    acStack_e0[0] = s___RADIANCE___Written_by_stb_imag_14030a550[8];

    acStack_e0[1] = s___RADIANCE___Written_by_stb_imag_14030a550[9];

    acStack_e0[2] = s___RADIANCE___Written_by_stb_imag_14030a550[10];

    acStack_e0[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0xb];

    acStack_e0[4] = s___RADIANCE___Written_by_stb_imag_14030a550[0xc];

    acStack_e0[5] = s___RADIANCE___Written_by_stb_imag_14030a550[0xd];

    acStack_e0[6] = s___RADIANCE___Written_by_stb_imag_14030a550[0xe];

    acStack_e0[7] = s___RADIANCE___Written_by_stb_imag_14030a550[0xf];

    local_d8[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x10];

    local_d8[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x11];

    local_d8[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x12];

    local_d8[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x13];

    local_d8[4] = s___RADIANCE___Written_by_stb_imag_14030a550[0x14];

    local_d8[5] = s___RADIANCE___Written_by_stb_imag_14030a550[0x15];

    local_d8[6] = s___RADIANCE___Written_by_stb_imag_14030a550[0x16];

    local_d8[7] = s___RADIANCE___Written_by_stb_imag_14030a550[0x17];

    acStack_d0[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x18];

    acStack_d0[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x19];

    acStack_d0[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1a];

    acStack_d0[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1b];

    acStack_d0[4] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1c];

    acStack_d0[5] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1d];

    acStack_d0[6] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1e];

    acStack_d0[7] = s___RADIANCE___Written_by_stb_imag_14030a550[0x1f];

    local_c8[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x20];

    local_c8[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x21];

    local_c8[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x22];

    local_c8[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x23];

    acStack_c4[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x24];

    acStack_c4[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x25];

    acStack_c4[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x26];

    acStack_c4[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x27];

    acStack_c0[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x28];

    acStack_c0[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x29];

    acStack_c0[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2a];

    acStack_c0[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2b];

    acStack_bc[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2c];

    acStack_bc[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2d];

    acStack_bc[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2e];

    acStack_bc[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x2f];

    local_b8[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x30];

    local_b8[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x31];

    local_b8[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x32];

    local_b8[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x33];

    acStack_b4[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x34];

    acStack_b4[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x35];

    acStack_b4[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x36];

    acStack_b4[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x37];

    acStack_b0[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x38];

    acStack_b0[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x39];

    acStack_b0[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3a];

    acStack_b0[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3b];

    acStack_ac[0] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3c];

    acStack_ac[1] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3d];

    acStack_ac[2] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3e];

    acStack_ac[3] = s___RADIANCE___Written_by_stb_imag_14030a550[0x3f];

    (*(code *)*param_1)(param_1[1],local_e8,0x41);

    uVar1 = FUN_14007a040(local_98,"EXPOSURE=          1.0000000000000\n\n-Y %d +X %d\n",param_3,

                          param_2);

    (*(code *)*param_1)(param_1[1],local_98,uVar1);

    do {

      FUN_140078120(param_1,param_2,param_4,uVar2,param_5);

      param_5 = param_5 + (longlong)(param_2 * param_4) * 4;

      uVar3 = uVar3 - 1;

    } while (uVar3 != 0);

    thunk_FUN_1402e9a80(uVar2);

    uVar2 = 1;

  }

  return uVar2;

}




