// Address: 0x1402dbc40
// Ghidra name: FUN_1402dbc40
// ============ 0x1402dbc40 FUN_1402dbc40 (size=472) ============


SLD_STATUS FUN_1402dbc40(int param_1,floating_point_string *param_2,ulonglong *param_3)



{

  SLD_STATUS SVar1;

  ulonglong uVar2;

  ulonglong *local_18;

  undefined1 local_10;

  

  if (param_1 < 6) {

    if (param_1 == 5) {

      uVar2 = (-(ulonglong)(param_2[0x308] != (floating_point_string)0x0) & 0x8000000000000000) +

              0x7ff0000000000000 | *param_3 & 0x7ff0000000000000 | 1;

    }

    else {

      local_18 = param_3;

      if (param_1 == 0) {

        local_10 = 1;

        SVar1 = FUN_1402dc3a8(param_2,&local_18);

        return SVar1;

      }

      if (param_1 == 1) {

        local_10 = 1;

        SVar1 = __crt_strtox::convert_hexadecimal_string_to_floating_type_common

                          (param_2,(floating_point_value *)&local_18);

        return SVar1;

      }

      if (param_1 == 2) {

        uVar2 = -(ulonglong)(param_2[0x308] != (floating_point_string)0x0) & 0x8000000000000000;

      }

      else if (param_1 == 3) {

        uVar2 = (-(ulonglong)(param_2[0x308] != (floating_point_string)0x0) & 0x8000000000000000) +

                0x7ff0000000000000 | *param_3 & 0x7ff0000000000000;

      }

      else {

        if (param_1 != 4) {

          return 1;

        }

        uVar2 = (-(ulonglong)(param_2[0x308] != (floating_point_string)0x0) & 0x8000000000000000) +

                0x7fffffffffffffff;

      }

    }

    *param_3 = uVar2;

  }

  else {

    if (param_1 != 6) {

      if (param_1 == 7) {

        *param_3 = 0;

      }

      else {

        if (param_1 == 8) {

          *param_3 = -(ulonglong)(param_2[0x308] != (floating_point_string)0x0) & 0x8000000000000000

          ;

          return 2;

        }

        if (param_1 == 9) {

          *param_3 = (-(ulonglong)(param_2[0x308] != (floating_point_string)0x0) &

                     0x8000000000000000) + 0x7ff0000000000000 | *param_3 & 0x7ff0000000000000;

          return 3;

        }

      }

      return 1;

    }

    *param_3 = 0xfff8000000000000;

  }

  return 0;

}




