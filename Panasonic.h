/*
 * PANASONIC_Class.h
 *
 *  Created on: Jan 12, 2024
 *      Author: minim
 */

#ifndef INC_PANASONIC_Class_H_
#define INC_PANASONIC_Class_H_


#include "cpp_Motor_Class_v2/Motor.h"


class Panasonic_motor : public Motor {
public:
	struct DXL_Setting{
		int empty;
		/* 통신 수신 */
		//uint32_t homeCnt_;	//DXL 기어 . 기준 home 위치

		/* 계산 */
		//int32_t rangeCnt_;	//동작 각도 Cnt 환산
	};

	Panasonic_motor(uint8_t gID, uint8_t sID);

    virtual ~Panasonic_motor() {
    }

    /* Motor Class 상속 */
    /* input 필수 기능 */
    /* init */
    void setSettingData_op(uint8_t gID, uint8_t sID, uint32_t data_1, uint32_t data_2) override;

    /* control */
    void setPosition(uint16_t targetPosition) override;		//MRS motion count 동작

    void setRawPosition(int32_t targetPosition) override;	//motor raw count 동작

    /* output 필수 기능*/
    uint16_t getPosition() const override ; 	//const 상태변경x 읽기전용
    int32_t getDefaultPosi() const override ;

    /* 공통 funtion */
    void init() override;		//Motor Active


private:
    /* 속성 */
	bool f_assign;	//true : 할당됨, false : 할당안됨

	DXL_Setting dxl_setting_;

};

#endif /* INC_PANASONIC_Class_H_ */
