package zadanie1;


import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;

import java.util.HashMap;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.ArgumentMatchers.anyLong;
import static org.mockito.Mockito.*;


class CarServiceTest {
    private CarService carService = mock(CarService.class);
    private CarDAO carDAO = mock(CarDAO.class);

    @Test
    @ExtendWith(MockitoExtension.class)
    void test() {

        HashMap<String,Long> map = new HashMap<>();
        map.put("2018", 111111L);
        map.put("2019", 133421L);
        map.put("2020", 112222L);
        map.put("2021", 145662L);

        Car car = new Car();
        car.setId(123L);
        car.setYearMileage(map);
        when(carDAO.findById(anyLong())).thenReturn(car);
        Car carRes = carDAO.findById(123L);
        verify(carDAO).findById(anyLong());

        when(carService.findMileageBetweenYears(anyLong(),anyString(),anyString())).thenReturn(100L);
        long resAny = carService.findMileageBetweenYears(1222L,"1998","2000");
        verify(carService).findMileageBetweenYears(anyLong(),anyString(),anyString());

        when(carService.findMileageBetweenYears(1222L,"1998","2002")).thenReturn(123444L);
        long res1222 = carService.findMileageBetweenYears(1222L,"1998","2002");
        verify(carService).findMileageBetweenYears(1222L,"1998","2002");

        assertEquals(100L, resAny);
        assertEquals(123444L,res1222);
        assertEquals(car,carRes);
    }
}