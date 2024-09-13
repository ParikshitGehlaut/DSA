public class DateToBinary{
    public static void main(String args[]){
        String date = "2024-09-08";
        String[] dateParts = date.split("-");
        int year = Integer.parseInt(dateParts[0]);
        int month = Integer.parseInt(dateParts[1]);
        int day = Integer.parseInt(dateParts[2]);

        String yearBinary = Integer.toBinaryString(year);
        String monthBinary = Integer.toBinaryString(month);
        String dayBinary = Integer.toBinaryString(day);

        System.out.println(yearBinary + "-" + monthBinary + "-" + dayBinary);
    }
}