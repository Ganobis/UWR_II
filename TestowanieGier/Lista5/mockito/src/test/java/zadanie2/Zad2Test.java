package zadanie2;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentCaptor;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;


import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
public class Zad2Test {
    @Mock
    private Session session;
    @Mock
    private DbLogger dbLogger;

    @InjectMocks
    private GenericDAO genericDAO = new GenericDAO();

    @Test
    void test1() throws SessionOpenException {
        doThrow(SessionOpenException.class).when(session).open();

        assertThrows(SessionOpenException.class, () ->{
            genericDAO.save(new Object());
        });
    }

    @Test
    void test2() throws CommitException, SessionOpenException {
        doThrow(CommitException.class).when(session).commitTransaction();
        ArgumentCaptor<Exception> captor = ArgumentCaptor.forClass(Exception.class);
        doNothing().when(dbLogger).log(captor.capture());
        genericDAO.save(new Object());
    }

    @Test
    void test3(){
        try{
            genericDAO.save(new Object());
        } catch (SessionOpenException e) {
            e.printStackTrace();
        }
        verify(session).save(any());
    }
}