package net.megaroid.mycalc;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import net.megaroid.expr.InfixCalculator;
import net.megaroid.math.Rational;

public class CalcActivity extends AppCompatActivity {

    EditText mExpr;
    TextView mResult;
    InfixCalculator mCalc;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calc);

        mExpr = (EditText)findViewById(R.id.edit_expr);
        mResult = (TextView) findViewById(R.id.text_result);
        mCalc = new InfixCalculator();

        Button buttonGo = (Button)findViewById(R.id.button_go);
        buttonGo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Rational result = mCalc.compute(mExpr.getText().toString());
                    mResult.setText(result.toString());
                } catch (Exception ex) {
                    mResult.setText("ERROR!");
                }
            }
        });
    }
}
